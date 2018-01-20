//#include "iostream"
//using namespace std;
//
//typedef enum
//{
//	INVALID = 0,
//	NOT_CONNECTED,
//	CONNECTED,
//	PAUSED_STOPPED,
//	PAUSED_ACQUIRING,
//	ACQUIRING
//}BeamFormerStates;
//
//typedef enum
//{
//	PAUSE,
//	UNPAUSE,
//	START_ACQUISITION,
//	STOP_ACQUISITION
//}StateCommands;
//
//class StateMachine
//{
//public:
//	StateMachine() { _CurrentState = INVALID; };
//	~StateMachine() {};
//
//	void TransferNextState(StateCommands cmmd);
//
//private:
//	BeamFormerStates _CurrentState;
//
//};
//
//void StateMachine::TransferNextState(StateCommands cmnd)
//{
//	switch (_CurrentState)
//	{
//	
//	case BeamFormerStates::CONNECTED:
//	{
//		if (cmnd == StateCommands::PAUSE)
//		{
//			_CurrentState = BeamFormerStates::PAUSED_STOPPED;
//			//Do other things here
//		}
//
//		else if (cmnd = StateCommands::START_ACQUISITION)
//		{
//			_CurrentState = BeamFormerStates::ACQUIRING;
//			//Do ther things here
//		}
//
//	}
//	break;
//
//	case BeamFormerStates::NOT_CONNECTED:
//	{
//		
//	}
//	break;
//
//	case BeamFormerStates::PAUSED_STOPPED:
//	{
//		if (cmnd == StateCommands::START_ACQUISITION)
//		{
//			_CurrentState = BeamFormerStates::PAUSED_ACQUIRING;
//			//Do other things here
//		}
//
//		else if (cmnd = StateCommands::UNPAUSE)
//		{
//			_CurrentState = BeamFormerStates::CONNECTED;
//			//Do ther things here
//		}
//	}
//	break;
//
//
//	case BeamFormerStates::PAUSED_ACQUIRING:
//	{
//		if (cmnd == StateCommands::STOP_ACQUISITION)
//		{
//			_CurrentState = BeamFormerStates::PAUSED_STOPPED;
//			//Do other things here
//		}
//
//		else if (cmnd = StateCommands::UNPAUSE)
//		{
//			_CurrentState = BeamFormerStates::ACQUIRING;
//			//Do ther things here
//		}
//	}
//	break;
//
//	case BeamFormerStates::ACQUIRING:
//	{
//		if (cmnd == StateCommands::PAUSE)
//		{
//			_CurrentState = BeamFormerStates::PAUSED_ACQUIRING;
//			//Do other things here
//		}
//
//		else if (cmnd = StateCommands::STOP_ACQUISITION)
//		{
//			_CurrentState = BeamFormerStates::CONNECTED;
//			//Do ther things here
//		}
//	}
//	break;
//
//	default:
//		break;
//	}
//}
//
//
//
//int main()
//{
//
//
//
//}