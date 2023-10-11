#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <preparaarvore.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_AbrirArquivo_clicked()
{
    try {
        // criando um arquivo de entrada, ou seja está saindo da memória secundaria para memória principal I(input)fstream
        std::ifstream arquivo;

        //Buscando o arquivo no disco
        //QFileDialog:: faz abrir a telinha de todos os arquivos do pc;
        QString nomeDoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"); // nessa tela, nome q aparece, C:/users\x\x\etc, vai pegar so arquivos csv ou txt;
        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");

        // abrindo um arquivo de entrada
        arquivo.open(nomeDoArquivo.toStdString().c_str()); // nao tem como colocar dados dentro de um arquivo fechado; pega o arquivo e transforma em string do C;

        // verificando erro de abertura do arquivo de entrada
        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser aberto"); // verifica se o arquivo ta aberto mesmo, se não LE;
        }
        std::string linha;
        QString texto= "";
        // lendo do arquivo
        getline(arquivo,linha);

        // Teste de fim do arquivo
        std::vector<int> ans;

        while(!arquivo.eof()){
            texto += QString::fromStdString(linha);
            //texto += "\n";
            getline(arquivo,linha);
        }
        //ui->textEdit_Arquivo->setText(texto);
        ans = km::PreparaArvore().SepararVertices(texto);
        arquivo.close();
        km::ArvoreBinaria obj;
        int tam = ans.size();
        for(int i= 0; i <tam; i++){
            obj.inserir(ans[i]);
        }
        std::vector<int> resposta;
        if(ui->comboBox->currentText() == "Pré-Fixado a Esquerda"){
            obj.imprimir(resposta,1);
        }
        if(ui->comboBox->currentText() == "Central a Esquerda"){
            obj.imprimir(resposta,2);
        }
        if(ui->comboBox->currentText() == "Pós-Fixado a Esquerda"){
            obj.imprimir(resposta,3);
        }
        if(ui->comboBox->currentText() == "Pré-Fixado a Direita"){
            obj.imprimir(resposta,4);
        }
        if(ui->comboBox->currentText() == "Central a Direita"){
            obj.imprimir(resposta,5);
        }
        if(ui->comboBox->currentText() == "Pós-Fixado a Direita"){
            obj.imprimir(resposta,6);
        }

        QString saida = "";
        tam = resposta.size();
        for(int i = 0; i<tam; i++){
            saida += QString::number(resposta[i]) + " ";
        }
        ui->textEdit_Arquivo->setText(saida);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

