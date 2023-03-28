public class Clube {
    public String nome;
    public int pontos;
    public int golsFeitos;
    public int golsSofridos;
    public int saldoGols;

    public Clube(String nome) {
        this.nome = nome;
        this. pontos = 0;
        golsFeitos = 0;
        this.golsSofridos = 0;
        this.saldoGols = 0;    }

    public void ganhar() {
        this.pontos += 3;
        atualizarSaldo();
    }

    public void empatar() {
        this.pontos += 1;
        atualizarSaldo();
    }

    public void perder() {
        atualizarSaldo();
    }

    private void atualizarSaldo() {
        this.saldoGols = golsFeitos - golsSofridos;
    }

    public String toString() {
        return "Nome: " + this.nome
                + "; Saldo: " + this.saldoGols
                + "; Gols  feitos: " + this.golsFeitos
                + "; Gols  sofridos: " + this.golsSofridos
                + "; Pontos: " + this.pontos
                + "; Saldo: " + this.saldoGols;
    }

}
