import scala.math.pow
import scala.math.log1p

class SystemBoeing747 extends System {
  // Parameter
  this.name = "Boeing747"

  // Getters
  def getName():String = this.name
  def getTF():String = {
    var s:String = ""
    s += "Discrete transfer function:\n\n"
    s += "           32.7 z^3 + 1.254 z^2 - 1036 z - 4.705\n"
    s += "-------------------------------------------------------\n"
  	s += "z^5 + 1.298 z^4 + 1.682 z^3 + 0.01004 z^2 + 0.0001753 z\n\n"
  	s
  }
  def getModel():String = {
    var s:String = ""
  	s += "Discrete-time state-space model with sample time 1 second:\n"
  	s +=   "a =\n" 
    s += "           x1         x2         x3         x4         x5\n"
    s += "x1   -0.00643     0.0263          0      -32.2          0\n"
    s += "x2    -0.0941     -0.624        820          0          0\n"
    s += "x3  -0.000222   -0.00153     -0.668          0          0\n"
    s += "x4          0          0          1          0          0\n"
    s += "x5          0         -1          0        830          0\n\n" 
    s += "b = \n"
    s += "       u1\n"
    s += "x1      0\n"
    s += "x2  -32.7\n"
    s += "x3  -2.08\n"
    s += "x4      0\n"
    s += "x5      0\n\n" 
    s += "c = \n"
    s += "    x1  x2  x3  x4  x5\n"
    s += "y1   0   0   0   0   1\n\n" 
    s += "d = \n"
    s += "    u1\n"
    s += "y1   0\n" 
    s
  }
  
  // Tf
  def tf(x:Double):Double = {
	// Your model here
//    (32.7*(s*s*s) + 1.254*(s*s) - 1036*s - 4.705)/((s*s*s*s*s) + 1.298*(s*s*s*s) + 1.682*(s*s*s) + 0.01004*(s*s) + 0.0001753*s)
//    (-22.47*pow(z,4)-251.6*pow(z,3)+71.44*pow(z,2)+191.7*z+8.56)/(pow(z,5)-3.45*pow(z,4)+4.627*pow(z,3)-3.178*pow(z,2)+1.273*z-0.273)
  }
  
  // toString
  override def toString():String = {
    var s:String = ""
    s += "Aircraft: "
    s += this.getName
    s += "\n"
    s += this.getTF
    s += this.getModel
    s
  }
}
  
