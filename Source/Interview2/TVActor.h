// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include <MediaAssets/Public/MediaPlayer.h>
#include "TVActor.generated.h"

UCLASS()
class INTERVIEW2_API ATVActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATVActor();

	UFUNCTION()
		void OnOverLapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);


	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> WidgetClass;

	void Stop();
	void Play();
	void Next();
	UPROPERTY(EditAnywhere, Category = "Class Types")
		UMediaPlayer* mediaPlayer;

	UPROPERTY(EditAnywhere, Category = "Class Types")
		TArray<UMediaSource*> mediaSource;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 

	UPROPERTY(VisibleInstanceOnly, Category = "Class Types")
		UUserWidget* WidgetObject;


	bool isVideoLoaded = false;

	bool isPaused = false;

	bool isPlayerIn = false;

	int currentVideoIndex = 0;
};
