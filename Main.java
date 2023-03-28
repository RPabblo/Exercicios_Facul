public class Main {
    public static void main(String[] args) {
        Clube c1 = new Clube("Flamengo");

        System.out.println(c1.toString());
        c1.golsFeitos = 5;
        c1.golsSofridos = 10;
        c1.ganhar();
        c1.ganhar();

        System.out.println(c1.toString());
    }
}