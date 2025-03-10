// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#include "WDice_ServerIndicator.h"
#include "Components/TextBlock.h"

void UWDice_ServerIndicator::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateRoleText();

}

void UWDice_ServerIndicator::UpdateRoleText()
{
	if (!Netmode) 
	{
		UE_LOG(LogTemp, Error, TEXT("UMyNetworkWidget: RoleText is not valid."));
		return;
	}

	FString RoleDescription;

	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("UMyNetworkWidget: World is null."));
		RoleDescription = TEXT("Invalid World");
	}
	else if (IsRunningDedicatedServer())
	{
		RoleDescription = TEXT("Dedicated Server");
	}
	else
	{
		ENetMode NetMode = World->GetNetMode();
		switch (NetMode)
		{
		case NM_Standalone:
			RoleDescription = TEXT("Standalone (Client)");
			break;
		case NM_ListenServer:
			RoleDescription = TEXT("Server");
			break;
		case NM_Client:
			RoleDescription = TEXT("Client");
			break;
		case NM_DedicatedServer:
			RoleDescription = TEXT("Dedicated Server (Shouldn't Happen Here)");
			break;
		default:
			RoleDescription = TEXT("Unknown NetMode");
			break;
		}
        
		// Log the detected NetMode for debugging
		UE_LOG(LogTemp, Warning, TEXT("UMyNetworkWidget: Detected NetMode - %s"), *RoleDescription);
	}

	// Set the text of the TextBlock
	Netmode->SetText(FText::FromString(RoleDescription));
}