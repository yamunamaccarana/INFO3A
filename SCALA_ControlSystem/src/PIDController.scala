class PIDController(kp:Double, ki:Double, kd:Double, f:Double, n:String) extends Controller (n:String){

	// Parameters
    private var KP:Double = kp
    private var KI:Double = ki
    private var KD:Double = kd
    private var freq:Double = f
    private var previousErr:Double = 0
    private var output = 0.
    private var offset = 0.
	private var history0 = 0. // memory 2
	private var history1 = 0.
	private var max = 999999999999.
	private var min = 0.
	private var controllerTime = 0.
	private var samplePeriod = 1
	private var vI = 0.
    
    // Getters
	def getKP()=this.KP
	def getKI()=this.KI
    def getKD()=this.KD
    def getFreq()=this.freq
    
    // Setters
    def setKP(k:Double) = this.KP = k
    def setKI(k:Double) = this.KI = k
    def setKD(k:Double) = this.KD = k
    def setFreq(fr:Double) = this.freq = fr

    /**
	 * Sets output clamping variables
	 * @param max
	 * @param min
	 */
	def setClamping(max:Double, min:Double) = {
		this.max = max
		this.min = min			
	}
	
	/**
	 * Sets an output offset
	 * @param offset
	 */
	def setOffset(offset:Double) = this.offset = offset
		
	/**
	 * Updates the PID controller
	 * @param in Sensor input
	 * @param set Set point
	 * @param deltaTime Time since last reading
	 */
	def update(in:Double, set:Double, deltaTime:Double):Double = {
		var vP = set - in; //value of proportional portion
	
		//Update the integrator
		this.controllerTime = this.controllerTime + deltaTime;
		if(this.controllerTime > this.samplePeriod){
			this.controllerTime -= this.samplePeriod;
			vI = 0; //Integration area

			//Push the error on the stack
			vI += history0;
			history1 = history0;

			history0 = vP //Push the error (proportional bit) to the stack
		}
		var vD = (history0 - history1) * deltaTime; //Derivative value
		
		output = vI*KI+vD*KD+vP*KP+offset;
		
		if(max > min){
			output = Math.max(output, min);
			output = Math.min(output, max);
		}
		output
	}
	
	/**
	 * Retrieves the PID output
	 * @return
	 */
	def getOutput() = output

}