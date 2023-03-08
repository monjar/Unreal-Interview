// Fill out your copyright notice in the Description page of Project Settings.


#include "TVActor.h"
#include "Blueprint/UserWidget.h"
// Sets default values
ATVActor::ATVActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	OnActorBeginOverlap.AddDynamic(this, &ATVActor::OnOverLapBegin);
	OnActorEndOverlap.AddDynamic(this, &ATVActor::OnOverLapEnd);

	

}

// Called when the game starts or when spawned 
void ATVActor::BeginPlay()
{
	Super::BeginPlay();
	WidgetObject = CreateWidget(GetWorld(), WidgetClass);

	APlayerController* FirstLocalPlayer = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// Ensure that the PlayerController and its InputComponent are valid before binding
	if (IsValid(FirstLocalPlayer) && IsValid(FirstLocalPlayer->InputComponent))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("1"));

		FirstLocalPlayer->InputComponent->BindAction("Play", IE_Released, this, &ATVActor::Play);
		FirstLocalPlayer->InputComponent->BindAction("Stop", IE_Released, this, &ATVActor::Stop);
		FirstLocalPlayer->InputComponent->BindAction("Next", IE_Released, this, &ATVActor::Next);


	}
}


void ATVActor::OnOverLapBegin(class AActor* OverlappedActor, class AActor* OtherActor) {

	if (WidgetObject != nullptr) {
		WidgetObject->AddToViewport();
	}
	isPlayerIn = true;
	
}

void ATVActor::Play() {

	if (!isPlayerIn)
		return;

	if (!isVideoLoaded) {
		isVideoLoaded = mediaPlayer->OpenSource(mediaSource[currentVideoIndex]);
	}

	if (isPaused && isVideoLoaded) {
		mediaPlayer->Play();
		isPaused = false;
	}
}

void ATVActor::Stop() {
	if (!isPlayerIn)
		return;

	if (!isPaused ) {
		mediaPlayer->Pause();
		isPaused = true;
	}
}

void ATVActor::Next() {
	if (!isPlayerIn)
		return;

	currentVideoIndex = (currentVideoIndex + 1) % mediaSource.Num();
	isVideoLoaded = false;
	Play();
}

void ATVActor::OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor) {

	if (WidgetObject != nullptr) {
		WidgetObject->RemoveFromParent();
	}

	isPlayerIn = false;


}

// Called every frame
void ATVActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
