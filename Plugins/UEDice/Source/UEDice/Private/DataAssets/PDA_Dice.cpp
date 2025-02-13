/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#include "DataAssets/PDA_Dice.h"
#include "Engine/StaticMesh.h"
#include "MeshDescription.h"
#include "Engine/StaticMeshSocket.h"


FPrimaryAssetId UPDA_Dice::GetPrimaryAssetId() const
{
    return FPrimaryAssetId("Dice", GetFName());
}
#if WITH_EDITOR


void UPDA_Dice::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

    // Check if the DiceMesh property was changed
    if (PropertyName == GET_MEMBER_NAME_CHECKED(UPDA_Dice, DiceMesh))
    {
        // Update the status of bHasValidMesh
        UpdateValidMeshStatus();
        // Autofill face details when DiceMesh is set or changed
        AutoFillFaceDetails();
        // Autofill face normals
        AutoFillFaceNormals();
    }
}

void UPDA_Dice::AutoFillFaceNormals()
{
    // Clear previous face normals
    FaceNormals.Empty();

    // Load the static mesh
    UStaticMesh* Mesh = DiceMesh.LoadSynchronous();
    // Iterate through all sockets that define the face normals
    // Iterate through all sockets on the mesh
    for (const UStaticMeshSocket* Socket : Mesh->Sockets)
    {
        // Retrieve the socket's relative rotation
        FQuat SocketRotation = Socket->RelativeRotation.Quaternion();

        // The normal is the forward vector of the socket's rotation
        FVector FaceNormal = SocketRotation.GetRightVector();

        // Add the calculated normal to the face normals array
        FaceNormals.Add(FaceNormal);

        // Optional: Log the normal for debugging
        UE_LOG(LogTemp, Log, TEXT("Face Normal calculated from socket %s: %s"), *Socket->GetName(), *FaceNormal.ToString());
    }

    // Log the total number of face normals calculated
    UE_LOG(LogTemp, Log, TEXT("Successfully auto-filled %d face normals."), FaceNormals.Num());
}

void UPDA_Dice::AutoFillFaceDetails()
{
    // Clear existing face labels
    FaceLabels.Empty();

    // Check if DiceMesh is valid
    if (DiceMesh.IsValid())
    {
        // Load the mesh asset synchronously
        UStaticMesh* Mesh = DiceMesh.LoadSynchronous();
        if (Mesh)
        {
            // Get all sockets from the mesh
            TArray<UStaticMeshSocket*> Sockets = Mesh->Sockets;

            // Sort the sockets alphabetically by their name
            // Sort the sockets based on the integer value of their names
            Algo::Sort(Sockets, [](const UStaticMeshSocket* A, const UStaticMeshSocket* B)
            {
                // Convert the socket names to integers
                int32 NameA = FCString::Atoi(*A->SocketName.ToString());
                int32 NameB = FCString::Atoi(*B->SocketName.ToString());
                return NameA < NameB;
            });

            // Populate FaceLabels with sorted socket names
            for (int32 i = 0; i < Sockets.Num(); ++i)
            {
                FText Label = FText::FromString(Sockets[i]->SocketName.ToString());
                FaceLabels.Add(Sockets[i]->SocketName.ToString(), Label);
            }

            // Log for confirmation
            UE_LOG(LogTemp, Log, TEXT("Auto-filled face details based on the DiceMesh sockets in alphabetical order."));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to load DiceMesh for auto-filling face details."));
        }
    }
}

void UPDA_Dice::UpdateValidMeshStatus()
{
    // Set bHasValidMesh based on the DiceMesh validity
    bHasValidMesh = DiceMesh.IsValid();
}
#endif