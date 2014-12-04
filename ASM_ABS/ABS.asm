/* example of ASM specification */

asm ABS

import STDL/StandardLibrary

//declare universes and functions
		
signature:

// domains 

	domain T subsetof Real //Braking Torque
	domain L subsetof Real //Longitudinal Wheel Slip
    enum domain ABS_State = {AUMENTO_T | MANTENIMENTO_TMAX | RIDUZIONE_T | MANTENIMENTO_TMIN }
	
// functions (monitored=in, out=out, controlled=internal)

	dynamic controlled stato: ABS_State

	dynamic monitored actualT: T
	dynamic monitored actualL: L
	dynamic monitored raggiungimTmax: Boolean //Se vero actualT=Tmax
	dynamic monitored raggiungimTmin: Boolean //Se vero actualT=Tmin
	dynamic monitored raggiungimLmax: Boolean //Se vero actualL=Lmax
	dynamic monitored raggiungimLmin: Boolean //Se vero actualL=Lmin

	dynamic out sysOut: String

// static functions 

	static tMax: T
	static tMin: T
	static lMax: L
	static lMin: L

// definitions 

definitions:
	
	domain T={0.00..1800.00}
	domain L={0.00..500.00} //*10^-3

	function tMax=1600.00
	function tMin=1000.00
	function lMax=350.00 //*10^-3
	function lMin=90.00 //*10^-3

//Rules

	rule r_raggiungimento_Tmax=
								if(stato=AUMENTO_T) then
									if(raggiungimTmax=true) then
										par
											stato:=MANTENIMENTO_TMAX
											sysOut:="E' stata raggiunta la forza massima di frenata: mantenimento forza massima di frenata."
										endpar
									else
										par
											stato:=AUMENTO_T
											sysOut:="Non è ancora stata raggiunta la forza massima di frenata: ulteriore aumento della forza di frenata."
										endpar
									endif
								endif

	rule r_raggiungimento_Lmax=
								if(stato=MANTENIMENTO_TMAX) then
									if(raggiungimLmax=true) then
										par
											stato:=RIDUZIONE_T
											sysOut:="E' stato raggiunto il limite massimo di slittamento: necessaria riduzione della forza di frenata."
										endpar
									else
										if(actualT<tMax) then //Improvviso cambio di aderenza
											par
												stato:=AUMENTO_T
												sysOut:="La forza di frenata è inferiore al limite massimo: aumento della forza di frenata."
											endpar
										else
											par
												stato:=MANTENIMENTO_TMAX
												sysOut:="Non è ancora stato raggiunto il limite massimo di slittamento: mantenimento della forza di frenata."
											endpar
										endif
									endif
								endif

	rule r_raggiungimento_Tmin=
								if(stato=RIDUZIONE_T) then
									if(raggiungimTmin=true) then
										par
											stato:=MANTENIMENTO_TMIN
											sysOut:="E' stata raggiunta la forza minima di frenata: mantenimento forza minima di frenata."
										endpar
									else
										par
											stato:=RIDUZIONE_T
											sysOut:="Non è ancora stata raggiunta la forza minima di frenata: ulteriore riduzione della forza di frenata."
										endpar
									endif
								endif

	rule r_raggiungimento_Lmin=
								if(stato=MANTENIMENTO_TMIN) then
									if(raggiungimLmin=true) then
										par
											stato:=AUMENTO_T
											sysOut:="E' stato raggiunto il limite minimo di slittamento: aumento della forza di frenata."
										endpar
									else
										if(actualT>tMin) then //Improvviso cambio di aderenza
											par
												stato:=RIDUZIONE_T
												sysOut:="La forza di frenata è ancora superiore al limite minimo: riduzione della forza di frenata."
											endpar
										else
											par
												stato:=MANTENIMENTO_TMIN
												sysOut:="Non è ancora stato raggiunto il limite minimo di slittamento: mantenimento della forza di frenata."
											endpar
										endif
									endif
								endif
	
// axioms
	
//Main Rule

	main rule r_Spec=seq
							r_raggiungimento_Tmax[]
							r_raggiungimento_Lmax[]
							r_raggiungimento_Tmin[]
							r_raggiungimento_Lmin[]
					endseq

//define the initial states 

	default init initial_state:

	function stato=AUMENTO_T
	function actualT=0.00
	function actualL=0.00
