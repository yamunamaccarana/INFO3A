object Test {
  def main(args: Array[String]) {
    printf("Welcome onboard!\n\n")
// PID----------------------------------------------
    // PID parameters initialization
	// Your PID param here
	val kp:Double = 1
	val ki:Double = 1
	val kd:Double = 1
	var f:Double = 1.
	val n:String = "PID-LTC4278"
	// PID initialization
	printf("Controller initialization.............................................\n")
    var PID = new PIDController(kp,ki,kd,f,n)
	printf("Gains set:\n")
	printf("Kp = "+PID.getKP+"\n")
	printf("Ki = "+PID.getKI+"\n")
	printf("Kd = "+PID.getKD+"\n")

// System-------------------------------------------
	printf("\nSystem model initialization............................................\n")
	var Boeing747 = new SystemBoeing747
	printf("System model ready!\n")
	printf("Techincal features:\n")
	printf(Boeing747.toString);
	
// Setting input:
    var setpoint:Double = 150. // desired altitude
    var err:Double = 0. // error
    var hPID:Double = 50. // actual altitude with PID
    var h:Double = 50. // actual altitude without PID
    var de:Double = 0.
    var dT:Double = 1.
    var hPIDOK = false // set true when setpoint reached
    var hOK = false

// LOOP
    var i:Double = 1
	while(i < 100){ // Simulation of 30 sec	  
	  de = PID.update(hPID,setpoint,0.001)
	  hPID = hPID + (Boeing747.tf(i/10) * (setpoint - hPID)) * de
	  if(hPID == setpoint && !hPIDOK){
	    printf("Altitudine desiderata raggiunta con PID al ciclo: "+i+"m.\n");
	    hPIDOK = true
	  }
	  if(!hPIDOK) printf("Ciclo "+i+": Altitudine (con PID):   "+hPID+"\n");
	  h = h + (Boeing747.tf(i/10) * (setpoint - h))
	  if(h == setpoint && !hOK){
	    printf("Altitudine desiderata raggiunta senza PID al ciclo: "+i+".\n");
	    hOK = true
	  }
	  if(!hOK) printf("Ciclo "+i+": Altitudine (senza PID):   "+h+"\n");
	  i += 1
	}
    if(!hPIDOK){
      printf("Altitudine desiderata raggiunta con tolleranza: "+(setpoint-hPID)+"m.\n");
    }
  }
}