//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include "fila.h"
#include "gtest/gtest.h"

using std::string;
using std::vector;
using std::to_string;

class TestePath: public ::testing::Test {
protected:
    string gen_string() {
        string r;

        for (int i=1 + (rand()%8); i > 0; i--) {
            r += 'A' + rand() % ('Z'-'A'+1);
        }
        return r;
    }

    virtual void SetUp() {
        srand(clock());
    }

    string v2str(const vector<string> & v) {
        string r;

        for (auto & w: v) r += w + ' ';
        return r;
    }
};

/*::testing::AssertionResult AssertSubstitui(const char* texto_expr,
                                               const char* sub_expr,
                                               const char* outra_expr,
                                               const char* correto_expr,
                                               const string & texto,
                                               const string & sub,
                                               const string & outra,
                                               const string & correto) {
    string res = substitui(texto, sub, outra);
    if (res == correto) return ::testing::AssertionSuccess();

    return ::testing::AssertionFailure() << "texto=" << texto << ", " << sub_expr << "=" << sub << ", " << outra_expr << "=" << outra << ": "
                                         << " resultado deveria ser: " << correto
                                         << ", mas sua função retornou: " << res;
}
*/

TEST_F(TestePath, Correta) {
    for (int num=10; num > 0; num--) {
        try {
            Fila q;
            vector<string> q0;

            int n = 5+(rand()%6);
            for (int j=n; j > 0; j--) {
                try {
                    string w = gen_string();
                    enfileira(q, w);
                    q0.push_back(w);
                } catch (...) {
                    FAIL() << "erro fatal ao enfileirar um dado";
                }
            }
            vector<string> r0, r;
            for (auto & w: q0) {
                try {
                    string k = desenfileira(q);
                    r0.push_back(w);
                    r.push_back(k);
                    if (k != w) {
                        FAIL() << "Erro: dado desenfileirado diferente do esperado ...."
                        << "sequência esperada até este ponto=" << v2str(r0)
                        << "; sequência obtida=" << v2str(r);
                    }
                } catch (...) {
                    FAIL() << "erro fatal ao desenfileirar um dado ... "
                                   << "sequência esperada até este ponto=" << v2str(r0)
                                   << "; sequência obtida=" << v2str(r);
                }
            }
        } catch (...) {
            FAIL() << "Erro ao criar uma fila";
        }
    }
}

TEST_F(TestePath, Comprimento) {
    for (int num=10; num > 0; num--) {
        try {
            Fila q;

            int n = 50+(rand()%51);
            for (int j=0; j < n; j++) {
                try {
                    enfileira(q, gen_string());
                    int len = comprimento(q);
                    if (len != j+1) {
                        FAIL() << "Comprimento diferente do esperado após enfileirar: deveria ser " << j+1 << ", mas retornou " << len;
                    }
                } catch (...) {
                    FAIL() << "erro fatal ao enfileirar um dado";
                }
            }
            for (int j=n; j > 0; j--) {
                try {
                    string k = desenfileira(q);
                    int len = comprimento(q);
                    if (len != j-1) {
                        FAIL() << "Comprimento diferente do esperado após desenfileirar: deveria ser " << j-1 << ", mas retornou " << len;
                    }
                } catch (...) {
                    FAIL() << "erro datal ao desenfileirar um dado";
                }
            }
        } catch (...) {
            FAIL() << "Erro ao criar uma fila";
            return;
        }
    }
}

