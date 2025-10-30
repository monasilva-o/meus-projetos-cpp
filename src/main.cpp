#include <iostream>
#include <locale.h>

using namespace std;

const int MAX = 100;

struct Participante {
    string nome, matricula, curso, email, celular, genero, tipo;
    int semestre, idade;
    bool esportes;
};

struct Atividade {
    string nome, tipo, local, data, hora;
    int vagas;
};

struct Inscricao {
    string matricula, nomeAtividade, data;
    bool presenca;
};

int main() {
    setlocale(LC_ALL, "portuguese");
    Participante participantes[MAX];
    Atividade atividades[MAX];
    Inscricao inscricoes[MAX];

    int totalParticipantes = 0;
    int totalAtividades = 0;
    int totalInscricoes = 0;
    int opcao;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Cadastrar Participante\n";
        cout << "2. Cadastrar Atividade\n";
        cout << "3. Cadastrar Inscrição\n";
        cout << "4. Alterar Participante\n";
        cout << "5. Alterar Atividade\n";
        cout << "6. Alterar Inscrição\n";
        cout << "7. Listar Atividades por Tipo\n";
        cout << "8. Listar Participantes Esportivos\n";
        cout << "9. Listar Inscrições por Data\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n*** Cadastro de Participante ***\n";
                cout << "1. Inserir novo participante\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opcao: ";
                cin >> voltar;
                if (voltar == 1 && totalParticipantes < MAX) 
				{
                    cout << "Nome: "; 
					cin >> participantes[totalParticipantes].nome;
					
                    cout << "Matrícula: "; 
					cin >> participantes[totalParticipantes].matricula;
					
                    cout << "Curso: "; 
					cin >> participantes[totalParticipantes].curso;
					
                    cout << "Semestre: "; 
					cin >> participantes[totalParticipantes].semestre;
					
                    cout << "Email: "; 
					cin >> participantes[totalParticipantes].email;
					
                    cout << "Celular: "; 
					cin >> participantes[totalParticipantes].celular;
					
                    cout << "Gênero: "; 
					cin >> participantes[totalParticipantes].genero;
					
                    cout << "Idade: "; 
					cin >> participantes[totalParticipantes].idade;
					
                    cout << "Tipo (organizador/palestrante/ouvinte): "; 
					cin >> participantes[totalParticipantes].tipo;
					
                    cout << "Participa de esportes? (1=Sim, 0=Nao): "; 
					cin >> participantes[totalParticipantes].esportes;
					
                    totalParticipantes++;
                    
                    cout << "Participante cadastrado com sucesso!\n";
                    
                } else if (voltar != 0 && voltar != 1) 
				{
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao == 2) {
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n*** Cadastro de Atividade ***\n";
                cout << "1. Inserir nova atividade\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: ";
                cin >> voltar;
                if (voltar == 1 && totalAtividades < MAX) 
				{
                    cout << "Nome da atividade: "; 
					cin >> atividades[totalAtividades].nome;
					
                    cout << "Tipo (palestra/oficina/competição/festa): "; 
					cin >> atividades[totalAtividades].tipo;
					
                    cout << "Local: "; 
					cin >> atividades[totalAtividades].local;
					
                    cout << "Data: "; 
					cin >> atividades[totalAtividades].data;
					
                    cout << "Hora: "; 
					cin >> atividades[totalAtividades].hora;
					
                    cout << "Vagas disponíveis: "; 
					cin >> atividades[totalAtividades].vagas;
					
                    totalAtividades++;
                    
                    cout << "Atividade cadastrada com sucesso!\n";
                } else if (voltar != 0 && voltar != 1) 
				{
                    cout << "Opcao inválida.\n";
                }
            }
        }
        else if (opcao == 3) {
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n*** Cadastro de Inscricao ***\n";
                cout << "1. Inserir nova inscrição\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: ";
                cin >> voltar;
                if (voltar == 1 && totalInscricoes < MAX) 
				{
                    string matricula, atividadeNome;
                    cout << "Matrícula do participante: "; 
					cin >> matricula;
                    cout << "Nome da atividade: "; 
					cin >> atividadeNome;
					
                    bool encontrada = false;
                    
                    for (int i = 0; i < totalAtividades; i++) 
					{
                        if (atividades[i].nome == atividadeNome) 
						{
                            if (atividades[i].vagas > 0) 
							{
                                cout << "Data da inscrição: ";
                                cin >> inscricoes[totalInscricoes].data;
                                
                                cout << "Confirma presença? (1=Sim, 0=Nao): ";
                                cin >> inscricoes[totalInscricoes].presenca;
                                
                                inscricoes[totalInscricoes].matricula = matricula;
                                inscricoes[totalInscricoes].nomeAtividade = atividadeNome;
                                
                                totalInscricoes++;
                                
                                atividades[i].vagas--;
                                
                                cout << "Inscrição realizada!\n";
                                
                            } else 
							{
                                cout << "Nao há vagas disponíveis nesta atividade.\n";
                            }
                            encontrada = true;
                            break;
                        }
                    }
                    if (!encontrada) cout << "Atividade não encontrada.\n";
                } else if (voltar != 0 && voltar != 1) 
				{
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao == 4) {
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n*** Alterar Participante ***\n";
                cout << "1. Alterar participante\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: "; 
				cin >> voltar;
                if (voltar == 1) 
				{
                    string busca;
                    cout << "Digite a matrícula: "; 
					cin >> busca;
					
                    for (int i = 0; i < totalParticipantes; i++) 
					{
                        if (participantes[i].matricula == busca) 
						{
                            cout << "Novo nome: "; 
							cin >> participantes[i].nome;
                            cout << "Participante alterado!\n";
                        }
                    }
                } else if (voltar != 0) {
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao == 5) {
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n*** Alterar Atividade ***\n";
                cout << "1. Alterar atividade\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: "; 
				cin >> voltar;
                if (voltar == 1) {
                    string busca;
                    cout << "Digite o nome da atividade: "; 
					cin >> busca;
                    for (int i = 0; i < totalAtividades; i++) 
					{
                        if (atividades[i].nome == busca) 
						{
                            cout << "Novo local: "; 
							cin >> atividades[i].local;
                            cout << "Atividade alterada!\n";
                        }
                    }
                } else if (voltar != 0) {
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao == 6) {
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n*** Alterar Inscrição ***\n";
                cout << "1. Alterar inscrição\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: "; 
				cin >> voltar;
                if (voltar == 1) 
				{
                    string mat, nome;
                    cout << "Digite a matrícula: "; 
					cin >> mat;
                    cout << "Digite o nome da atividade: "; 
					cin >> nome;
                    for (int i = 0; i < totalInscricoes; i++) 
					{
                        if (inscricoes[i].matricula == mat && inscricoes[i].nomeAtividade == nome) 
						{
                            cout << "Nova data de inscrição: ";
                            cin >> inscricoes[i].data;
                            cout << "Confirma Presença? (1=Sim, 0=Nao): ";
                            cin >> inscricoes[i].presenca;
                            cout << "Inscrição alterada!\n";
                        }
                    }
                } else if (voltar != 0) {
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao == 7) 
		{
            int voltar = 1;
            while (voltar != 0) 
			{
                cout << "\n*** Listar Atividades por Tipo ***\n";
                cout << "1. Listar\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: "; 
				cin >> voltar;
                if (voltar == 1) 
				{
                    string tipoBusca;
                    cout << "Digite o tipo: "; 
					cin >> tipoBusca;
                    for (int i = 0; i < totalAtividades; i++) 
					{
                        if (atividades[i].tipo == tipoBusca) 
						{
                            cout << atividades[i].nome << " - " << atividades[i].local << "\n";
                        }
                    }
                } else if (voltar != 0) 
				{
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao == 8) 
		{
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n*** Listar Participantes Esportivos ***\n";
                cout << "1. Listar\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: "; 
				cin >> voltar;
                if (voltar == 1) 
				{
                    for (int i = 0; i < totalParticipantes; i++) 
					{
                        if (participantes[i].esportes) 
						{
                            cout << participantes[i].nome << " - " << participantes[i].curso << "\n";
                        }
                    }
                } else if (voltar != 0) {
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao == 9) {
            int voltar = 1;
            while (voltar != 0) {
                cout << "\n-- Listar Inscrições por Data --\n";
                cout << "1. Listar\n";
                cout << "0. Voltar\n";
                cout << "Escolha uma opção: "; 
				cin >> voltar;
                if (voltar == 1) 
				{
                    string dataBusca;
                    cout << "Digite a data: "; 
					cin >> dataBusca;
                    for (int i = 0; i < totalInscricoes; i++) 
					{
                        if (inscricoes[i].data == dataBusca) 
						{
                            cout << inscricoes[i].matricula << " - " << inscricoes[i].nomeAtividade << "\n";
                        }
                    }
                } else if (voltar != 0) 
				{
                    cout << "Opção inválida.\n";
                }
            }
        }
        else if (opcao != 0) {
            cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}
