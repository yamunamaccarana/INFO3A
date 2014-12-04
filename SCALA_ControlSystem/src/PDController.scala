class PDController(kp:Double, kd:Double, f:Double, n:String) extends Controller (n:String){

	// Parameters
    private var KP:Double = kp
    private var KI:Double = 0
    private var KD:Double = kd
    private var freq:Double = f
    private var previousErr:Double = 0

    // Getters
	def getKP()=this.KP
    def getKD()=this.KD
    def getFreq()=this.freq
    
    // Setters
    def setKP(k:Double) = this.KP = k
    def setKD(k:Double) = this.KD = k
    def setFreq(fr:Double) = this.freq = fr
    
    // Methods
    def PDProcess(err:Double):Double = {
      var output = 0.
      output = this.KP * err + this.KD * (err - this.previousErr) * this.freq // P + D
      this.previousErr = err // update error
      output // return output      
    }
}