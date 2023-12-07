// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileWeapon.h"
#include "Projectile.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Case.h"

void AProjectileWeapon::Fire(const FVector& TraceHitLocation)
{
    Super::Fire(TraceHitLocation);
    SpawnCase();
    if(!HasAuthority()) return;
    if(WeaponMesh == nullptr) return;
    const USkeletalMeshSocket* MuzzleSocket = WeaponMesh->GetSocketByName(FName("MuzzleFlash"));
    FTransform MuzzleSocketTransform;
    if(MuzzleSocket) MuzzleSocketTransform = MuzzleSocket->GetSocketTransform(WeaponMesh);
    
    FVector ProjectileHitLocation = TraceHitLocation - MuzzleSocketTransform.GetLocation();
    FRotator ProjectileRotation = ProjectileHitLocation.Rotation();
    if(ProjectileClass)
    {   
        UWorld* World = GetWorld();
        if(World == nullptr) return;
        FActorSpawnParameters SpawnParams;
        SpawnParams.Instigator = Cast<APawn>(GetOwner());
        SpawnParams.Owner = GetOwner();
        World->SpawnActor<AProjectile>(ProjectileClass, MuzzleSocketTransform.GetLocation(), ProjectileRotation, SpawnParams);
    }
}

void AProjectileWeapon::SpawnCase()
{
    if(WeaponMesh == nullptr) return;
    const USkeletalMeshSocket* BulletCaseSocket = WeaponMesh->GetSocketByName(FName("AmmoEject"));
    FTransform CaseSocketTransform;
    if(BulletCaseSocket) CaseSocketTransform = BulletCaseSocket->GetSocketTransform(WeaponMesh);

    if(BulletCaseClass)
    {   
        UWorld* World = GetWorld();
        if(World == nullptr) return;
        World->SpawnActor<ACase>(BulletCaseClass, CaseSocketTransform);
    }
}


