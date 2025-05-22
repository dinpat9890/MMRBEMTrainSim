package Mumbai_Metro;

import org.sikuli.script.FindFailed;
import org.sikuli.script.Key;
import org.sikuli.script.Screen;
import java.io.IOException; // Import the IOException class to handle errors
import java.io.File;
import java.io.FileWriter;

/**
 * Created Automation Script for PowerMenu Starting to load SMC, SCC & PT
 * Screens using sikuli tool.
 *
 * @author ext-asatis
 */

public class powerMenuStartup {
	static FileWriter output;
	Screen center_Screen = new Screen(); // Center
	Screen left_Screen = new Screen(2); // Left
	Screen s = new Screen(); // Center

	private void powerMenu() throws IOException, FindFailed {
		
		output = new FileWriter(FilePathConstant.POWER_MENU + "Automation.log");

		center_Screen.find(FilePathConstant.POWER_MENU + "powerScreen1.PNG");
		center_Screen.doubleClick(FilePathConstant.POWER_MENU + "powerScreen1.PNG");
		center_Screen.wait(14.0);

		/*
		 * find_Click_Test(center_Screen, FilePathConstant.POWER_MENU +
		 * "powerScreen.PNG", true, "", "PowerMenu Startup", 12.0);
		 * 
		 * find_Click_Test(center_Screen, FilePathConstant.POWER_MENU + "StartSim.PNG",
		 * false, "", "PowerMenu Startup", 17.0);
		 */

	}

	private void smc() throws IOException, FindFailed {
		/*
		 * find_Click_Test(center_Screen, FilePathConstant.IMAGE_PATH_1 +
		 * "DefaultManager.PNG", false, "", "SMC Login", 1.0);
		 * find_Click_Test(center_Screen, FilePathConstant.IMAGE_PATH_1 +
		 * "SuperUser.PNG", false, "", "SMC Login", 1.0); find_Click_Test(center_Screen,
		 * FilePathConstant.IMAGE_PATH_1 + "password.PNG", false, "password",
		 * "SMC Login", 1.0); find_Click_Test(center_Screen,
		 * FilePathConstant.IMAGE_PATH_1 + "okbutton.PNG", false, "", "SMC Login", 3.0);
		 */
		output = new FileWriter(FilePathConstant.IMAGE_PATH_1 + "Automation.log");
		center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "DefaultManager.PNG");
		center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "DefaultManager.PNG");
		center_Screen.wait(2.0);

		center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "SuperUser.PNG");
		center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "SuperUser.PNG");
		center_Screen.wait(2.0);

		center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "password.PNG");
		center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "password.PNG");
		center_Screen.wait(2.0);
		center_Screen.type("password");

		center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okbutton.PNG");
		center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "okbutton.PNG");
		center_Screen.wait(2.0);

	}

	// private void find_Click_Test(Screen screen, String filepath, boolean
	// isDoubleClick, String type_text,
	/*
	 * String functionality, double waitTime) { try { screen.find(filepath); if
	 * (isDoubleClick) screen.doubleClick(filepath); else screen.click(filepath);
	 * 
	 * if (!type_text.isEmpty()) screen.type(type_text); screen.wait(waitTime);
	 * System.out.println("screen " + screen.x + " --- filepath " + filepath +
	 * " ----- screen.exists(filepath) " + screen.exists(filepath)); if
	 * (screen.exists(filepath) != null)
	 * System.out.println("\n****Test Case : Test case Passed****\n"); else
	 * System.out.println("\n****Test Case : Test case Failed****\n"); } catch
	 * (FindFailed e) { System.out.println(functionality); } }
	 */

	private void trainBuilder() throws IOException {
		try {

			/*
			 * find_Click_Test(center_Screen, FilePathConstant.IMAGE_PATH_1 + "train.PNG",
			 * false, "", "Train Builder", 1.0); find_Click_Test(center_Screen,
			 * FilePathConstant.IMAGE_PATH_1 + "driving_motor_car_1_2.PNG", false, "",
			 * "Train Builder", 1.0); find_Click_Test(center_Screen,
			 * FilePathConstant.IMAGE_PATH_1 + "rear_button.PNG", false, "",
			 * "Train Builder", 1.0);
			 */

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "train.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "train.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "driving_motor_car_1_2.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "driving_motor_car_1_2.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "rear_button.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "rear_button.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trailer_car_1_2.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "trailer_car_1_2.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trailer_car_1_2.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "trailer_car_1_2.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "motor_car_1_2.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "driving_motor_car_2_1.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "driving_motor_car_2_1.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "firstMotor.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "firstMotor.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "motorCar12.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "motorCar12.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "motorCar21.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "motorCar21.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trailer21.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "trailer21.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "DrivingCar21.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "DrivingCar21.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "Edit.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "FullLoad.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "saveAsTrainBuilder.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "saveAsTrainBuilder.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trainBuildername.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "trainBuildername.PNG");
			center_Screen.type("simTrain1");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "openTrain.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "openTrain.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "selectTrain.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "selectTrain.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "editSimTrain1.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "editSimTrain1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "okButton1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "save.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "save.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.wait(1.0);

			System.out.println("**** Train Builder All Test Cases Passed successfully****");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	private void userCreate() throws IOException {
		try {
			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Users.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Users.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "newTrainee.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "newTrainee.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "UserLastName.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "UserLastName.PNG");
			center_Screen.type("Agrawal");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "UserFirstName.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "UserFirstName.PNG");
			center_Screen.type("Neha");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "EmployeeNumber.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "EmployeeNumber.PNG");
			center_Screen.type("2022");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "userClassification.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "userClassification.PNG");
			center_Screen.type("Developer");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "WorkLocation.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "WorkLocation.PNG");
			center_Screen.type("Pune");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Copy_Scenerio_save_as_new.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Copy_Scenerio_save_as_new.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "editTrainee.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "editTrainee.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Naming1.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Naming1.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okbutton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "okbutton.PNG");

			System.out.println("**** Created User successfully****");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	private void userEdit() throws IOException {
		try {
			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "editPune.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "editPune.PNG");
			center_Screen.type(Key.BACKSPACE);
			center_Screen.type(Key.BACKSPACE);
			center_Screen.type(Key.BACKSPACE);
			center_Screen.type(Key.BACKSPACE);
			center_Screen.type("Nagpur");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "save.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "save.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "doneScenerioOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "doneScenerioOkButton.PNG");
			center_Screen.wait(1.0);

			System.out.println("****Edited User successfully****");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	/*
	 * private void userDelete() throws IOException { try {
	 * center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "DeleteTrainee.PNG");
	 * center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "DeleteTrainee.PNG");
	 * center_Screen.wait(1.0);
	 * 
	 * center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "editimage.PNG");
	 * center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "editimage.PNG");
	 * center_Screen.wait(1.0);
	 * 
	 * center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "okbutton.PNG");
	 * center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "okbutton.PNG");
	 * 
	 * center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "DeleteButton.PNG");
	 * center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "DeleteButton.PNG");
	 * center_Screen.wait(1.0);
	 * 
	 * center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "yes_buton.PNG");
	 * center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "yes_buton.PNG");
	 * center_Screen.wait(2.0);
	 * 
	 * center_Screen.find(FilePathConstant.IMAGE_PATH_1 +
	 * "scenerioGroupOkButton.PNG");
	 * center_Screen.click(FilePathConstant.IMAGE_PATH_1 +
	 * "scenerioGroupOkButton.PNG"); center_Screen.wait(1.0);
	 * 
	 * if (s.exists(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG") !=
	 * null) System.out.println("\n****Test Case 6: Test case Passed****\n"); else
	 * System.out.println("\n****Test Case 6: Test case Failed****\n"); } catch
	 * (FindFailed e) { e.printStackTrace(); } }
	 */
	private void instructor() throws IOException {
		try {
			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Instructor.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Instructor.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "NewInstructor.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "NewInstructor.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "InstructorLastName.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "InstructorLastName.PNG");
			center_Screen.type("Agrawal");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "InstructorFirstName.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "InstructorFirstName.PNG");
			center_Screen.type("Neha");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "SelectPrivilageGroup.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "SelectPrivilageGroup.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "SuperUser1.PNG");
			center_Screen.doubleClick(FilePathConstant.IMAGE_PATH_1 + "SuperUser1.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Password12.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Password12.PNG");
			center_Screen.type("12345");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "saveAsNew.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "saveAsNew.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "scenerioGroupOkButton.PNG");
			center_Screen.wait(1.0);

			System.out.println("**** Created Instructor successfully****");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	private void scenario() throws IOException {
		try {

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Scenarios.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Scenarios.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "NewScenerio.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "NewScenerio.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "ScenerioName.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "ScenerioName.PNG");
			center_Screen.type("MumbaiMetroTrain");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "up1.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "up1.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "down1.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "down1.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "selectTrack.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "selectTrack.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Feature_track.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Feature_track.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trackOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "trackOkButton.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Trains.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Trains.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "AddSimulated.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "AddSimulated.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trainName.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "trainName.PNG");
			center_Screen.type("SimTrain");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "TripNumber.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "TripNumber.PNG");

			center_Screen.type(Key.BACKSPACE);
			center_Screen.type(Key.BACKSPACE);
			center_Screen.type(Key.BACKSPACE);
			center_Screen.type(Key.BACKSPACE);
			center_Screen.type("1234");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "selectType.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "selectType.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "EMU_6_car.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "EMU_6_car.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trainConsistOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "trainConsistOkButton.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "selectPosition.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "selectPosition.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "map_click.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "map_click.PNG");

			center_Screen.mouseMove(FilePathConstant.IMAGE_PATH_1 + "map_drop.PNG");

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "trackOk.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "trackOk.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "TrainOk1.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "TrainOk1.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "saveAsNew.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "saveAsNew.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "doneScenerioOkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "doneScenerioOkButton.PNG");
			center_Screen.wait(3.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "Exit.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "Exit.PNG");
			center_Screen.wait(3.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "yes_buton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "yes_buton.PNG");
			center_Screen.wait(3.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH_1 + "StartSim.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH_1 + "StartSim.PNG");
			center_Screen.wait(25.0);

			System.out.println("**** Created Scenario successfully****");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	private void startSimulator() throws IOException {
		try {

			/*
			 * center_Screen.find(FilePathConstant.PT + "SoftPLC.PNG");
			 * 
			 * center_Screen.rightClick(FilePathConstant.PT + "SoftPLC.PNG");
			 * center_Screen.wait(2.0);
			 * 
			 * center_Screen.find(FilePathConstant.PT + "CloseWindow.PNG");
			 * center_Screen.click(FilePathConstant.PT + "CloseWindow.PNG");
			 * center_Screen.wait(2.0);
			 */

			/*
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "SessionSetup.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "SessionSetup.PNG");
			 * center_Screen.wait(2.0);
			 */
			output = new FileWriter(FilePathConstant.IMAGE_PATH + "Automation.log");

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SelectInstructor.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SelectInstructor.PNG");
			center_Screen.wait(3.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SuperUserDefault.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SuperUserDefault.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SelectScenario.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SelectScenario.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "EMU_8_Car_Track.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "EMU_8_Car_Track.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SelectDriversCabTrainee.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SelectDriversCabTrainee.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "DriverTraineeName.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "DriverTraineeName.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.wait(3.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "StartSession.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "StartSession.PNG");
			center_Screen.wait(88.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SimulatorStatus.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SimulatorStatus.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "Play.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "Play.PNG");
			center_Screen.wait(2.0);

			if (s.exists(FilePathConstant.IMAGE_PATH + "Play.PNG") != null)
				System.out.println("\n****Test Case 13: Test case Passed****\n");
			else
				System.out.println("\n****Test Case 13: Test case Failed****\n");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	private void environmentControl() throws IOException {
		try {
			output = new FileWriter(FilePathConstant.IMAGE_PATH + "Automation.log");

			center_Screen.find(FilePathConstant.IMAGE_PATH + "EnvironmentControl.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "EnvironmentControl.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "Rain.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "Rain.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "Fog.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "Fog.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "WindDirection.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "WindDirection.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "WindVelocity.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "WindVelocity.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "Lightening.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "Lightening.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "ScriptingManegement.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "ScriptingManegement.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "RainIntensityPercentage.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "RainIntensityPercentage.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.wait(1.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "ZeroPercent.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "ZeroPercent.PNG");
			center_Screen.wait(2.0);

			center_Screen.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			center_Screen.wait(3.0);

			/*
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "FireImmediateEvent.PNG");
			 * center_Screen.wait(1.0);
			 * 
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "SendEvent.PNG");
			 * center_Screen.wait(1.0);
			 * 
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "SelectEvent.PNG");
			 * center_Screen.wait(1.0);
			 * 
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "Light.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "Light.PNG");
			 * center_Screen.wait(1.0);
			 * 
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			 * center_Screen.wait(2.0);
			 * 
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "SelectEventState.PNG");
			 * center_Screen.wait(2.0);
			 * 
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "LighteningOn.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "LighteningOn.PNG");
			 * center_Screen.wait(2.0);
			 * 
			 * center_Screen.find(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			 * center_Screen.click(FilePathConstant.IMAGE_PATH + "OkButton.PNG");
			 * center_Screen.wait(2.0);
			 */

			if (s.exists(FilePathConstant.IMAGE_PATH + "OkButton.PNG") != null)
				System.out.println("\n****Test Case 14: Test case Passed****\n");
			else
				System.out.println("\n****Test Case 14: Test case Failed****\n");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}

	private void pt() throws IOException {

		try {
			
			output = new FileWriter(FilePathConstant.PT + "Automation.log");

			/*
			 * left_Screen.find(FilePathConstant.PT + "PT.PNG");
			 * left_Screen.click(FilePathConstant.PT + "PT.PNG"); left_Screen.wait(2.0);
			 */

			left_Screen.find(FilePathConstant.PT + "PTInstructor.PNG");
			left_Screen.click(FilePathConstant.PT + "PTInstructor.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Train1.PNG");
			left_Screen.click(FilePathConstant.PT + "Train1.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "DriverDesk.PNG");
			left_Screen.click(FilePathConstant.PT + "DriverDesk.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "masterController.PNG");
			left_Screen.click(FilePathConstant.PT + "masterController.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "masterController1.PNG");
			left_Screen.click(FilePathConstant.PT + "masterController1.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "OnKey.PNG");
			left_Screen.click(FilePathConstant.PT + "OnKey.PNG");
			left_Screen.wait(3.0);

			left_Screen.find(FilePathConstant.PT + "back.PNG");
			left_Screen.click(FilePathConstant.PT + "back.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "panel1.PNG");
			left_Screen.click(FilePathConstant.PT + "panel1.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "ParkingBrakeOff.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "ParkingBrakeOff.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "back.PNG");
			left_Screen.click(FilePathConstant.PT + "back.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "back.PNG");
			left_Screen.click(FilePathConstant.PT + "back.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "OperatingPanel2.PNG");
			left_Screen.click(FilePathConstant.PT + "OperatingPanel2.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "panel2.PNG");
			left_Screen.click(FilePathConstant.PT + "panel2.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "PowerOn.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "PowerOn.PNG");
			left_Screen.wait(3.0);

			left_Screen.find(FilePathConstant.PT + "vcbClose.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "vcbClose.PNG");
			left_Screen.wait(3.0);

			left_Screen.find(FilePathConstant.PT + "back.PNG");
			left_Screen.click(FilePathConstant.PT + "back.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "back.PNG");
			left_Screen.click(FilePathConstant.PT + "back.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "masterController.PNG");
			left_Screen.click(FilePathConstant.PT + "masterController.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "masterController1.PNG");
			left_Screen.click(FilePathConstant.PT + "masterController1.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Deadman.PNG");
			left_Screen.click(FilePathConstant.PT + "Deadman.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "UpClick.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			left_Screen.find(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.doubleClick(FilePathConstant.PT + "Pmax.PNG");
			left_Screen.wait(2.0);

			if (s.exists(FilePathConstant.PT + "Pmax.PNG") != null)
				System.out.println("\n****Test Case 15: Test case Passed****\n");
			else
				System.out.println("\n****Test Case 15: Test case Failed****\n");

		} catch (FindFailed e) {
			e.printStackTrace();
		}
	}


	public static void main(String[] args) throws FindFailed {
		try {
			// create a file

			powerMenuStartup obj = new powerMenuStartup();
			obj.powerMenu();

			obj.smc();

			obj.trainBuilder();
			obj.userCreate();
			// obj.userEdit();

			// obj.userDelete();

			obj.instructor();
			obj.scenario();

			obj.startSimulator();
			obj.environmentControl();

			obj.pt();

		} catch (IOException e) {
			System.out.println("An error occurred.");
			e.printStackTrace();
		}
	}
}