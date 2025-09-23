// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomSlimeComponent.h"

// Sets default values for this component's properties
UCustomSlimeComponent::UCustomSlimeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	// ...
}

//======================================================================
//Creating and setting up the material parameters and his mesh
//======================================================================
UMaterialInstanceDynamic* UCustomSlimeComponent::CreateMesh()
{
	if (!GetOwner()) return nullptr;
	
	UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(GetOwner()->AddComponentByClass(UStaticMeshComponent::StaticClass(), false, FTransform::Identity, false));
	if (!MeshComp) return nullptr;
	MeshComp->SetCastShadow(false);
	MeshComp->SetRelativeScale3D(FVector(2.5f));
	MeshComp->SetStaticMesh(Mesh);
	MeshComp->SetMaterial(0, SlimeMaterial);
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->SetRelativeLocation(FVector(0, 0, -20.0f));
	DynMat = UMaterialInstanceDynamic::Create(SlimeMaterial,this);
	MeshComp->SetMaterial(0, DynMat);
	DynMat->SetScalarParameterValue(TEXT("SphereCount"), NumSpheres);
	ActorRotationForward=GetOwner()->GetActorRotation().Quaternion().GetForwardVector();
	ActorRotationUp=GetOwner()->GetActorRotation().Quaternion().GetUpVector();
	ActorRotationRight=GetOwner()->GetActorRotation().Quaternion().GetRightVector();
	DynMat->SetVectorParameterValue(TEXT("ActorUpRot"), ActorRotationUp);
	DynMat->SetVectorParameterValue(TEXT("ActorRightRot"), ActorRotationRight);
	DynMat->SetVectorParameterValue(TEXT("ActorForwardRot"), ActorRotationForward);
	DynMat->SetVectorParameterValue(TEXT("BoxCenter"), BoxCenter);
	DynMat->SetVectorParameterValue(TEXT("BoxSize"), BoxSize);
	DynMat->SetScalarParameterValue(TEXT("BoxRoundness"), BoxRoundness);
	DynMat->SetVectorParameterValue(TEXT("SphereCenter1"), SphereCenter1);
	DynMat->SetVectorParameterValue(TEXT("SphereCenter2"), SphereCenter2);
	DynMat->SetVectorParameterValue(TEXT("SphereCenter3"), SphereCenter3);
	DynMat->SetVectorParameterValue(TEXT("SphereCenter4"), SphereCenter4);
	DynMat->SetVectorParameterValue(TEXT("SphereCenter5"), SphereCenter5);
	DynMat->SetScalarParameterValue(TEXT("SphereRadius1"), SphereRadius1);
	DynMat->SetScalarParameterValue(TEXT("SphereRadius2"), SphereRadius2);
	DynMat->SetScalarParameterValue(TEXT("SphereRadius3"), SphereRadius3);
	DynMat->SetScalarParameterValue(TEXT("SphereRadius4"), SphereRadius4);
	DynMat->SetScalarParameterValue(TEXT("SphereRadius5"), SphereRadius5);
	DynMat->SetScalarParameterValue(TEXT("SphereCount"), NumSpheres);
	DynMat->SetScalarParameterValue(TEXT("Smoothness"), Smoothness);
	DynMat->SetScalarParameterValue(TEXT("MaxSteps"), MaxSteps);
	DynMat->SetScalarParameterValue(TEXT("MaxDistance"), MaxDistance);
	DynMat->SetScalarParameterValue(TEXT("HitThreshold"), HitThreshold);
	DynMat->SetTextureParameterValue(TEXT("Tex"),TextureObject);
	DynMat->SetScalarParameterValue(TEXT("TextureScale"), TextureScale);
	DynMat->SetScalarParameterValue(TEXT("IsNoise"), IsNoise? 1.0f : 0.0f);
	DynMat->SetScalarParameterValue(TEXT("NoiseScale"), noiseScale);
	DynMat->SetScalarParameterValue(TEXT("NoiseIndex"), noiseIndex);
	DynMat->SetVectorParameterValue(TEXT("ExternalSphereCenter1"),ExternalSphereCenter1);
	DynMat->SetVectorParameterValue(TEXT("ExternalSphereCenter2"),ExternalSphereCenter2);
	DynMat->SetVectorParameterValue(TEXT("ExternalSphereCenter3"),ExternalSphereCenter3);
	DynMat->SetVectorParameterValue(TEXT("ExternalSphereCenter4"),ExternalSphereCenter4);
	DynMat->SetVectorParameterValue(TEXT("ExternalSphereCenter5"),ExternalSphereCenter5);
	DynMat->SetScalarParameterValue(TEXT("ExternalSphereRadius1"),ExternalSphereRadius1);
	DynMat->SetScalarParameterValue(TEXT("ExternalSphereRadius2"),ExternalSphereRadius2);
	DynMat->SetScalarParameterValue(TEXT("ExternalSphereRadius3"),ExternalSphereRadius3);
	DynMat->SetScalarParameterValue(TEXT("ExternalSphereRadius4"),ExternalSphereRadius4);
	DynMat->SetScalarParameterValue(TEXT("ExternalSphereRadius5"),ExternalSphereRadius5);
	DynMat->SetScalarParameterValue(TEXT("ExternalSphereCount"), ExternalNumSpheres);
	DynMat->SetScalarParameterValue(TEXT("ExternalRotationSpeed"),ExternalRotationSpeed);
	DynMat->SetVectorParameterValue(TEXT("BaseColor"),BaseColor);
	DynMat->SetScalarParameterValue(TEXT("UseTexture"), useTexture? 1.0f : 0.0f);
	
	return DynMat;
}

//======================================================================
//Updating the rotation in the material as well, only if the actor is set to move
//======================================================================
void UCustomSlimeComponent::UpdateRotation()
{
	ActorRotationForward=GetOwner()->GetActorRotation().Quaternion().GetForwardVector();
	ActorRotationUp=GetOwner()->GetActorRotation().Quaternion().GetUpVector();
	ActorRotationRight=GetOwner()->GetActorRotation().Quaternion().GetRightVector();
	DynMat->SetVectorParameterValue(TEXT("ActorUpRot"), ActorRotationUp);
	DynMat->SetVectorParameterValue(TEXT("ActorRightRot"), ActorRotationRight);
	DynMat->SetVectorParameterValue(TEXT("ActorForwardRot"), ActorRotationForward);
}

// Called when the game starts
void UCustomSlimeComponent::BeginPlay()
{
	Super::BeginPlay();

	SetComponentTickEnabled(canMove);
	
}


// Called every frame
void UCustomSlimeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateRotation();
}

