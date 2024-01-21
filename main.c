#include "./files/struct.h"
#include "./files/struct.c"

#include "./files/Menus/menus.h"
#include "./files/Menus/menu.c"
#include "./files/Menus/menu_cadastro.c"

#include "./files/Quartos/quartos.h"
#include "./files/Quartos/def_predio.c"

#include "./files/Funcionario/login_func.c"

int main(){
    int opcao;

    Definindo_Predio();

    opcao = menu();

    switch (opcao)
    {
    case 1:
        menu_cadastro();
        system("PAUSE");
        system("cls");
        return main(); //Aqui é para retornar ao menu, que está no início do main
        break;
    case 2:
        // login(&funcionario);
        system("PAUSE");
        system("cls");
        break;
    default:
        break;
    }
}