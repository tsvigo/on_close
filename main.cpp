#include "dialog.h"

#include <QApplication>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
///.
                                                                                             
#include <QPushButton>                                                                                                
#include <QtDebug>                                                                                                    
#include <signal.h>  
using namespace std;
#include <fstream>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <QCoreApplication>

#include <initializer_list>

#include <unistd.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The Button class
///. 
//class Button : public QPushButton {
//  Q_OBJECT
//public slots:
//  void doSomething() { qDebug() << "About to quit!"; }
//};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ignoreUnixSignals(std::initializer_list<int> ignoreSignals) {
    // all these signals will be ignored.
    for (int sig : ignoreSignals)
        signal(sig, SIG_IGN);
}

void catchUnixSignals(std::initializer_list<int> quitSignals) {
    auto handler = [](int sig) -> void {
        // blocking and not aysnc-signal-safe func are valid
        printf("\nquit the application by signal(%d).\n", sig);
        // Здесь обработка функций
        QCoreApplication::quit();
    };
    
    sigset_t blocking_mask;   
    sigemptyset(&blocking_mask);  
    for (auto sig : quitSignals) 
        sigaddset(&blocking_mask, sig);  
        
    struct sigaction sa;   
    sa.sa_handler = handler;   
    sa.sa_mask    = blocking_mask;  
    sa.sa_flags   = 0;    
    
    for (auto sig : quitSignals)   
        sigaction(sig, &sa, nullptr);
}

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// .
/// 
//void signalhandler(int sig){
//  if(sig==SIGINT){
//  //  qApp->quit();
//   std::cout << "тест"// stderr.toStdString().c_str()
//     << std::endl; 
//    QApplication::beep();
//  }
//}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// . 
int main(int argc, char *argv[])
     {
          QApplication a(argc, argv);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          /// \brief w
    catchUnixSignals({SIGQUIT, SIGINT, SIGTERM, SIGHUP, SIGKILL});

    // do your initialization and other stuff
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          /// \brief w
          ///.         
          Dialog w;
          w.show();
           //  std::cout << "тест"     << std::endl; 
       //  QApplication::setQuitOnLastWindowClosed(false);
         // signal(SIGINT, signalhandler);
         return a.exec();
     }

