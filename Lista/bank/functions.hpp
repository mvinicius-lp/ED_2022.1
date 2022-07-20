//funçoes
#pragma once
#include <iostream>
#include <list>
#include <vector>

using namespace std;

//cria struct cliente
struct Cliente {
    string nome;
    int docs;
    int paciencia;

    Cliente(string nome, int docs, int paciencia) : nome(nome), docs(docs), paciencia(paciencia) {}

    string str() {
        return nome + ":" + to_string(docs) + ":" + to_string(paciencia); 
    }
};

//cria banco e seus parametros
class Banco {
private:
    vector<Cliente*> caixas;
    list<Cliente*> fila_entrada {};
    list<Cliente*> fila_saida {};
    int docs_received {0};
    int docs_lost {0};
    int tics {0};
    int quantidade {0};
    
public:
    Banco(int caixas) : caixas(caixas){}

    void insere(Cliente *client) {
        this->fila_entrada.push_back(client);
        
        ++quantidade;
    }

    bool vazio() {
        return this->quantidade == 0;
    }


    void passar_tempo() {
        if (!this->fila_saida.empty()) {
            for (auto it = fila_saida.begin(); it != fila_saida.end(); it++) {
                this->docs_lost += (*it)->docs;
                
                auto backup = it;
                
                it = this->fila_saida.erase(it);
                
                delete *backup;
            }

            --quantidade;
        }


        for (auto &elemento_caixa : this->caixas) {
            if (elemento_caixa != nullptr) {
                if (elemento_caixa->docs > 0) {
                    --elemento_caixa->docs;

                    this->docs_received++;
                } else {
                    auto pessoa = elemento_caixa;
                    this->fila_saida.push_back(pessoa);
                    
                    elemento_caixa = nullptr;
                }
            } else {
                if (fila_entrada.empty()) {
                    break;
                }
                
                elemento_caixa = this->fila_entrada.front();

                this->fila_entrada.pop_front();
            }
        }

        if (!fila_entrada.empty()) {
            for (auto it = fila_entrada.begin(); it != fila_entrada.end(); it++) {
                if ((*it)->paciencia > 0) {
                   (*it)->paciencia--;
                } else {
                    auto pessoa = (*it);
                    
                    fila_saida.push_back(pessoa);
                    
                    it = fila_entrada.erase(it);
                }
            }
        }

        ++tics;
    }
    //show parametros
    void show_all() {
        for(auto &client : this->caixas) {
            cout << "[" << (client == nullptr ? "" : client->str()) << "]";
        }
        
        cout << "\nin :{ ";
        
        for(auto &client : this->fila_entrada)
            cout << (client == nullptr ? "" : client->str()) << " ";
        
        cout << "}\nout:{ ";
        
        for(auto &client : this->fila_saida)
            cout << (client == nullptr ? "" : client->str()) << " ";
        
        cout << "}\n";
    }
    //gets
    int get_received() {
        return this->docs_received;
    }

    int get_lost() {
        return this->docs_lost;
    }

    int get_tics() {
        return this->tics;
    }
};