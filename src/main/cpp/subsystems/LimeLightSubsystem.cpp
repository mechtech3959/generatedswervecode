#include "subsystems/LimeLightSubsystem.h"
// class LimeLight : frc2::SubsystemBase{};

LimeLight::LimeLight(std::string name) {
  limelight = nt::NetworkTableInstance::GetDefault().GetTable(name);
};
void LimeLight::updateTracking(std::string name) {
  double tx = LimelightHelpers::getTX(name);
  double ty = LimelightHelpers::getTY(name);
  double ta = LimelightHelpers::getTA(name);
  double tv = LimelightHelpers::getTV(name);
  if (tv < 1.0) {
    drivecmd = 0.0;
    turncmd = 0.0;
    distance = 0.0;
    LLHasTarget = false;
  } else {
    LLHasTarget = true;
    turncmd = tx;
    drivecmd = ta;
  }
};
frc::Pose2d LimeLight::poseEst() {};