#include "./files/struct.h"
#include "./files/struct.c"

#include "./files/Menus/menus.h"
#include "./files/Menus/menu.c"

#include "./files/Quartos/quartos.h"
#include "./files/Quartos/def_predio.c"

#include "./files/Funcionario/cadastro_func.c"
#include "./files/Funcionario/login_func.c"

int main(){
    int opcao;
    Funcionario funcionario;

    Definindo_Predio();

    opcao = menu();

    switch (opcao)
    {
    case 1:
        cadastrar(&funcionario);
        system("PAUSE");
        system("cls");
        return main(); //Aqui é para retornar ao menu, que está no início do main
        break;
    case 2:
        // Colocar quando possivel uma verificação se o arquivo de cadastro funcionario está vazio ou não.
        login(&funcionario);
        system("PAUSE");
        system("cls");
        break;
    default:
        break;
    }
}