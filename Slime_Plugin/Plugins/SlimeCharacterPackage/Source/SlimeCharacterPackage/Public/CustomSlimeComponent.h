// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomSlimeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLIMECHARACTERPACKAGE_API UCustomSlimeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCustomSlimeComponent();

	//=================================
	//Spheres
	//=================================
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres",meta=(UIMin="0.0",UIMax="4.0",ClampMin="0.0",ClampMax="4.0"))
	int32 NumSpheres;

	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=0",EditConditionHides))
	FVector SphereCenter1;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=0",EditConditionHides))
	float SphereRadius1;

	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=1",EditConditionHides))
	FVector SphereCenter2;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=1",EditConditionHides))
	float SphereRadius2;
	
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=2",EditConditionHides))
	FVector SphereCenter3;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=2",EditConditionHides))
	float SphereRadius3;
	
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=3",EditConditionHides))
	FVector SphereCenter4;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=3",EditConditionHides))
	float SphereRadius4;
	
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=4",EditConditionHides))
	FVector SphereCenter5;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|Spheres", meta=(EditCondition="NumSpheres>=4",EditConditionHides))
	float SphereRadius5;

	//=================================
	//External Spheres
	//=================================
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres",meta=(UIMin="0.0",UIMax="5.0",ClampMin="0.0",ClampMax="5.0"))
	int32 ExternalNumSpheres;
	
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=1",EditConditionHides))
	FVector ExternalSphereCenter1;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=1",EditConditionHides))
	float ExternalSphereRadius1;
	
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=2",EditConditionHides))
	FVector ExternalSphereCenter2;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=2",EditConditionHides))
	float ExternalSphereRadius2;

	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=3",EditConditionHides))
	FVector ExternalSphereCenter3;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=3",EditConditionHides))
	float ExternalSphereRadius3;

	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=4",EditConditionHides))
	FVector ExternalSphereCenter4;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=4",EditConditionHides))
	float ExternalSphereRadius4;

	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=5",EditConditionHides))
	FVector ExternalSphereCenter5;
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=5",EditConditionHides))
	float ExternalSphereRadius5;
	
	UPROPERTY(EditAnywhere, Category="Slime|SDF|External Spheres", meta=(EditCondition="ExternalNumSpheres>=1",EditConditionHides))  
	float ExternalRotationSpeed;                                                                                                      

	//=================================
	//Base Box
	//=================================
	UPROPERTY(EditAnywhere,Category="Slime|SDF|Base Box")
	FVector BoxCenter;
	UPROPERTY(EditAnywhere,Category="Slime|SDF|Base Box")
	FVector BoxSize;
	UPROPERTY(EditAnywhere,Category="Slime|SDF|Base Box")
	float BoxRoundness=8.0f;

	//=================================     
	//Raymarch                             
	//=================================     
	UPROPERTY(EditAnywhere,Category="Slime|Raymarch")
	float Smoothness=50.0f;
	UPROPERTY(EditAnywhere,Category="Slime|Raymarch")
	int32 MaxSteps=256;
	UPROPERTY(EditAnywhere,Category="Slime|Raymarch")
	float MaxDistance=1000.0f;
	UPROPERTY(EditAnywhere,Category="Slime|Raymarch")
	float HitThreshold=0.001f;
	UPROPERTY(EditAnywhere,Category="Slime|Raymarch")     
	bool canMove=false;                                    
	
	//=================================     
	//Texture                              
	//=================================
	UPROPERTY(EditAnywhere,Category="Slime|Texture",meta=(EditCondition="!useTexture"))  
	FLinearColor BaseColor;                                                               
	UPROPERTY(EditAnywhere,Category="Slime|Texture")
	bool useTexture=false;
	UPROPERTY(EditAnywhere,Category="Slime|Texture",meta=(EditCondition="useTexture"))
	UTexture2D* TextureObject;
	UPROPERTY(EditAnywhere,Category="Slime|Texture",meta=(EditCondition="useTexture"))  
	float TextureScale=0.01f;



	//================================= 
	//Owner Actor                       
	//================================= 
	UPROPERTY()   
	FVector ActorPosition;
	UPROPERTY()            
	FVector ActorRotationForward;
	UPROPERTY()            
	FVector ActorRotationRight;
	UPROPERTY()            
	FVector ActorRotationUp;

	//=================================
	//Noise                     
	//=================================
	UPROPERTY(EditAnywhere,Category="Slime|Noise") 
	bool IsNoise=true;
	UPROPERTY(EditAnywhere,Category="Slime|Noise",meta=(EditCondition="IsNoise",EditConditionHides)) 
	float noiseIndex=5.0f;
	UPROPERTY(EditAnywhere,Category="Slime|Noise",meta=(EditCondition="IsNoise",EditConditionHides))   
	float noiseScale=0.05f;

	//=================================
	//CallableFunctions                           
	//=================================
	UFUNCTION(BlueprintCallable, Category="Slime|Mesh")
	UMaterialInstanceDynamic* CreateMesh();
	UFUNCTION(BlueprintCallable, Category="Slime|Mesh")     
	void UpdateRotation();                  

	//=================================  
	//CallableFunctions                  
	//=================================  
	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere)
	UMaterialInstance* SlimeMaterial;
	UPROPERTY()
	UMaterialInstanceDynamic* DynMat;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
