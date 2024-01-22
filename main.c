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

    do{
        opcao = menu();

        switch (opcao)
        {
        case 1:
            cadastrar(&funcionario);
            system("PAUSE");
            system("cls");
            break;
        case 2:
            if(funcionario.usuario == 0 || funcionario.senha == 0){
                printf("Nenhum funcionario cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else{
                login(&funcionario);
            }
            system("PAUSE");
            system("cls");
            break;
        default:
            break;
        }
    }while(opcao != 3);
}