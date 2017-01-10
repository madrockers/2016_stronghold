// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef AUTONOMOUS_COMMAND_H
#define AUTONOMOUS_COMMAND_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <BuiltInAccelerometer.h>


/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	AutonomousCommand(int AutonomousState);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

    int m_AutonomousState;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
    std::string align;
    std::string defense;
    std::string spy;
    int defense_int = 1;
    int align_int = 1;
    int spy_int;
    bool use_spy_bot = false;
    bool completed_checks = false;
    BuiltInAccelerometer Accel; //initialize the accelerometer

	// define variables
	double TimeToPassDefense[8];
	double slot_forward_time[4];
	double defense_motor_init[8];
	int trackLightPixelBias[4];
	double turnTowardsGoalTime[4];
	struct timeval tv;
	double ref_time=0.0;
	unsigned int slotLocation;
	bool useSpyBotFunction, useSpyPersonReflectors;
	enum AutoState { moveForwardOverDefense, trackLights, moveForwardToShoot,
		turnTowardsGoal, trackGoals, stop, shoot };
	enum DefenseType { PORTCULLIS, CHEVAL_DE_FRISE, MOAT, RAMPART, DRAW_BRIDGE,
		SALLY_PORT, ROCK_WALL, ROUGH_TERRAIN };
	DefenseType defenseType;
	int accel_cnt = 0;
	short current_goal_error, current_lights_error, current_goal_row;
	double MIN_ROW_TO_SHOOT, MAX_ROW_TO_SHOOT;
	double startTrackLightsTime, startTrackGoalTime; // seconds
	double moveForwardToShootRefTime;
	double timeInTurnTowardsGoal;
	const int DEADBAND = 5; // tweek this
	const double MAX_AUTO_TIME = 15.0;

	AutoState autoState = moveForwardOverDefense;
};

#endif