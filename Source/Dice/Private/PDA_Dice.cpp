// Fill out your copyright notice in the Description page of Project Settings.
#include "Dice/Public/PDA_Dice.h"
#include "Engine/StaticMesh.h"
#include "MeshDescription.h"
#include "Engine/StaticMeshSocket.h"


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
        // Auto-fill face details when DiceMesh is set or changed
        AutoFillFaceDetails();
    }
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
                FaceLabels.Add(Sockets[i]->SocketName.ToString(), Sockets[i]->SocketName.ToString());
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