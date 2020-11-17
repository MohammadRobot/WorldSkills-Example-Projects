package frc.robot.subsystems;

//Vendor imports
import com.studica.frc.TitanQuad;
import com.studica.frc.ServoContinuous;

//WPI imports
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;

/**
 * DriveTrain class 
 * <p>
 * This class creates the instance of the Titan and enables and sets the speed of the defined motor. 
 */
public class DriveTrain extends SubsystemBase
{
    /**
     * Motors
     */
    private TitanQuad motor;
    private ServoContinuous servoC;

    /**
     * Constructor
     */
    public DriveTrain()
    {
        //Motors
        motor = new TitanQuad(Constants.TITAN_ID, Constants.MOTOR);
        servoC = new ServoContinuous(Constants.SERVO_C);
    }

    /**
     * Sets the speed of the motor
     * <p>
     * @param speed range -1 to 1 (0 stop)
     */
    public void setMotorSpeed(double speed)
    {
        motor.set(speed);
    }

    /**
     * Sets the speed of the continuous servo motor
     * <p>
     * @param speed range -1 to 1 (0 stop)
     */
    public void setServoSpeed(double speed)
    {
        servoC.set(speed);
    }
}