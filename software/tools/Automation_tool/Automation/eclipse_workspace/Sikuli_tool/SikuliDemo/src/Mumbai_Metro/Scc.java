package Mumbai_Metro;

import org.sikuli.script.FindFailed;
import org.sikuli.script.Screen;
import java.io.IOException; // Import the IOException class to handle errors

/**
 * Created Automation Script for Scc using sikuli tool.
 *
 * @author ext-asatis
 */

public class Scc {

	Screen S, S1;
	int i;
	String sessionName, mode;

	public Scc() throws IOException {

		S = new Screen();
		S1 = new Screen(1);
		i = 0;
		sessionName = null;
		mode = null;
	}

	private void startSimulator() throws IOException {
		try {
			S1.find(FilePathConstant.IMAGE_PATH + "SCC.PNG");
			S1.doubleClick(FilePathConstant.IMAGE_PATH + "SCC.PNG");
			S1.wait(3.0);

			S.find(FilePathConstant.PT + "SoftPLC.PNG");
			S.rightClick(FilePathConstant.PT + "SoftPLC.PNG");
			S.wait(1.0);

			S.find(FilePathConstant.PT + "CloseWindow.PNG");
			S.click(FilePathConstant.PT + "CloseWindow.PNG");
			S.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SimulatorStatus.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SimulatorStatus.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SessionSetup.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SessionSetup.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SelectInstructor.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SelectInstructor.PNG");
			S1.wait(3.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SuperUserDefault.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SuperUserDefault.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SelectScenario.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SelectScenario.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "EMU_8_Car_Track.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "EMU_8_Car_Track.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SelectDriversCabTrainee.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SelectDriversCabTrainee.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "DriverTraineeName.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "DriverTraineeName.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.wait(3.0);

			S1.find(FilePathConstant.IMAGE_PATH + "StartSession.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "StartSession.PNG");
			S1.wait(28.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SimulatorStatus.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SimulatorStatus.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "Play.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "Play.PNG");
			S1.wait(2.0);

			System.out.println("**** Simulator Lauched successfully****");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	private void environmentControl() throws IOException {
		try {
			S1.find(FilePathConstant.IMAGE_PATH + "EnvironmentControl.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "EnvironmentControl.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "Rain.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "Rain.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "Fog.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "Fog.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "WindDirection.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "WindDirection.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "WindVelocity.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "WindVelocity.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "Lightening.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "Lightening.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "ScriptingManegement.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "ScriptingManegement.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "RainIntensityPercentage.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "RainIntensityPercentage.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "ZeroPercent.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "ZeroPercent.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "Light.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "Light.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.wait(1.0);

			S1.find(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "LighteningOn.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "LighteningOn.PNG");
			S1.wait(2.0);

			S1.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			S1.wait(2.0);
			System.out.println("**** Environment Control Test Cases Passed successfully****");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) throws FindFailed {
		try {
			Scc obj = new Scc();

			obj.startSimulator();
			obj.environmentControl();

		} catch (IOException e) {
			System.out.println("An error occurred.");
			e.printStackTrace();
		}
	}
}