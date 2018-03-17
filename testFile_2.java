class SwitchDemo{
    public static void main(String args[]){
        int marks = Integer.parseInt(args[0]);
        switch(marks/10){
            case 8:
                System.out.println("Excellent");
                break;
            case 7:
                System.out.println("Very Good");
                break;
            case 6:
                System.out.println("Good");
                break;
            case 5:
                System.out.println("Work Hard");
                break;
            case 4:
                System.out.println("Poor");
                break;
            case 0:
                System.out.println("Very Poor");
                break;
            default :
                System.out.println("Invalid value Entered");
            }
    }
}
