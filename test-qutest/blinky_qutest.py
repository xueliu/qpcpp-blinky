# test-script for QUTest unit testing harness
# see https://www.state-machine.com/qtools/html

def on_reset():
    expect_pause()
    glb_filter(GRP_ON)
    continue_test()
    expect("@timestamp TE0-Arm  Obj=Blinky::inst.m_timeEvt,AO=Blinky::inst,*")
    expect("===RTC===> St-Init  Obj=Blinky::inst,State=QHsm::top->off")
    expect("@timestamp LED 0")
    expect("===RTC===> St-Entry Obj=Blinky::inst,State=off")
    expect("@timestamp Init===> Obj=Blinky::inst,State=off")
    current_obj(OBJ_SM_AO,"Blinky::inst")
    current_obj(OBJ_TE,"Blinky::inst.m_timeEvt")

test("TIMEOUT_SIG->Blinky::inst")
query_curr(OBJ_SM)
expect("@timestamp Query-SM Obj=Blinky::inst,State=off")
query_curr(OBJ_AO)
expect("@timestamp Query-AO Obj=Blinky::inst,Que<Free=11,Min=11>")
query_curr(OBJ_TE)
expect("@timestamp Query-TE Obj=Blinky::inst.m_timeEvt,Rate=0,Sig=TIMEOUT_SIG,Tim=50,Int=50,Flags=0x80")
current_obj(OBJ_MP,"EvtPool1")
query_curr(OBJ_MP)
expect("@timestamp Query-MP Obj=EvtPool1,Free=10,Min=10")
post("TIMEOUT_SIG")
expect("@timestamp QF-New   Sig=TIMEOUT_SIG,*")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=Blinky::inst,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=Blinky::inst,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=Blinky::inst,Sig=TIMEOUT_SIG,State=off")
expect("@timestamp LED 1")
expect("===RTC===> St-Entry Obj=Blinky::inst,State=on")
expect("@timestamp ===>Tran Obj=Blinky::inst,Sig=TIMEOUT_SIG,State=off->on")
expect("@timestamp QF-gc    Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("timeEvt->off (tick)")
current_obj(OBJ_TE,"Blinky::inst.m_timeEvt")
tick()
expect("           Tick<0>  Ctr=*")
expect("@timestamp TE0-Post Obj=Blinky::inst.m_timeEvt,Sig=TIMEOUT_SIG,AO=Blinky::inst")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=Blinky::inst,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=Blinky::inst,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=Blinky::inst,Sig=TIMEOUT_SIG,State=off")
expect("@timestamp LED 1")
expect("===RTC===> St-Entry Obj=Blinky::inst,State=on")
expect("@timestamp ===>Tran Obj=Blinky::inst,Sig=TIMEOUT_SIG,State=off->on")
expect("@timestamp Trg-Done QS_RX_TICK")

test("timeEvt->on (tick)", NORESET)
tick()
expect("           Tick<0>  Ctr=*")
expect("@timestamp TE0-Post Obj=Blinky::inst.m_timeEvt,Sig=TIMEOUT_SIG,AO=Blinky::inst")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=Blinky::inst,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=Blinky::inst,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=Blinky::inst,Sig=TIMEOUT_SIG,State=on")
expect("@timestamp LED 0")
expect("===RTC===> St-Entry Obj=Blinky::inst,State=off")
expect("@timestamp ===>Tran Obj=Blinky::inst,Sig=TIMEOUT_SIG,State=on->off")
expect("@timestamp Trg-Done QS_RX_TICK")