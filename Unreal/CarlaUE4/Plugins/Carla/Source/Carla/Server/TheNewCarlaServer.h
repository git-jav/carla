// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "Carla/Actor/ActorView.h"
#include "Carla/Sensor/DataStream.h"

#include "CoreMinimal.h"

class UCarlaEpisode;

class FTheNewCarlaServer
{
public:

  FTheNewCarlaServer();

  ~FTheNewCarlaServer();

  void Start(uint16_t Port);

  void NotifyBeginEpisode(UCarlaEpisode &Episode);

  void NotifyEndEpisode();

  void AsyncRun(uint32 NumberOfWorkerThreads);

  void RunSome(uint32 Milliseconds);

  void Stop();

  FDataStream OpenStream() const;

  FDataMultiStream OpenMultiStream() const;

  bool CheckSensorStream(FActorView &ActorView);

private:

  class FPimpl;
  TUniquePtr<FPimpl> Pimpl;
};
