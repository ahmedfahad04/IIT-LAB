package Mobile_Banking_System_Phase_2;

public class Bank {
    public void start_banking(){

        Bkash wahid_reza = new Bkash("MD. Wahid Reza", "01766610087", "2547");
        Rocket mizan = new Rocket("Dr. Mizanur Rahman", "01533484399", null);
        Nagad solaiman = new Nagad("Mr. Solaiman Shukhon", "01815047916", "1234");

        //Bkash
        System.out.println("###################### Bkash ######################");
        wahid_reza.add_money(2500);
        wahid_reza.send_money(1200, "01822016195", "2547");
        wahid_reza.withdraw(1000, "2547");
        wahid_reza.change_pin("2547", "1478");
        wahid_reza.send_money(900,"01924088626", "2548");
        System.out.println(wahid_reza);

        //Rocket
        System.out.println("###################### Rocket ######################");
        mizan.add_money(10000);
        mizan.set_new_pin("01533484399", "1254");
        mizan.withdraw(6000, "1254");
        mizan.send_money(5000,"01766610087" ,"1254");
        mizan.withdraw(12000, "1254");
        mizan.send_money(1500,"01815047916", "1254");
        System.out.println(mizan);

        //Nagad
        System.out.println("###################### Nagad ######################");
        solaiman.add_money(2000);
        solaiman.withdraw(300,"1234");
        solaiman.add_money(5000);
        solaiman.withdraw(2000,"3254");
        solaiman.send_money(1000, null, "1234");
        solaiman.add_money(40000);

        System.out.println(solaiman);



    }
}
