#include "MyActorComponent.h"

UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMyActorComponent::DoSomething()
{
	UE_LOG(LogTemp, Log, TEXT("DoSomething called on %s"), *GetOwner()->GetName());
}
