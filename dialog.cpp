#include "dialog.h"
#include "ui_dialog.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
///.
#include <QApplication>                                                                                               
#include <QPushButton>                                                                                                
#include <QtDebug>                                                                                                    
#include <signal.h>  
using namespace std;
#include <fstream>
#include <iostream>
#include <QGuiApplication>
#include <signal.h>  
///
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// .
/// 
//void signalhandler(int sig){
//  if(sig==SIGINT){
//  //  qApp->quit();
//   std::cout << "тест"// stderr.toStdString().c_str()
//     << std::endl; 
//  //   exit(0   );
//  }
//}
 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ./ 
Dialog::Dialog(QWidget *parent)
     : QDialog(parent)
     , ui(new Ui::Dialog)
     {
          ui->setupUi(this);
         // qApp()->setQuitOnLastWindowClosed(false);
         QApplication::setQuitOnLastWindowClosed(false);
         //  signal(SIGINT, signalhandler);
     }

Dialog::~Dialog()
     {
          delete ui;
     }

//void MyDialog::reject()
//{
//    QMessageBox::StandardButton resBtn = QMessageBox::Yes;
//    if (changes) {
//        resBtn = QMessageBox::question( this, APP_NAME,
//                                        tr("Are you sure?\n"),
//                                        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
//                                        QMessageBox::Yes);
//    }
//    if (resBtn == QMessageBox::Yes) {
//        QDialog::reject();
//    }
//}


void Dialog::on_pushButton_clicked()
{
    QApplication::setQuitOnLastWindowClosed(true);
 //   signal(sig, SIG_IGN);
// SIGQUIT;
  //  exit(0   );
//     signal(SIGINT, signalhandler);
}

