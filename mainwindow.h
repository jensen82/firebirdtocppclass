#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QMap>

class QSqlQueryModel;
class QModelIndex;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void connectSignals();
    
private:
    Ui::MainWindow *ui;
    
    QString m_sDBHost;
    QString m_sDBPassword;
    QString m_sDBUser;
    QString m_sDBFile;
    int m_Dialect;
    QString m_DBCharset;
    
    QSqlDatabase db;
    QSqlQueryModel * tablemodel;
    QSqlQueryModel * fieldsmodel;
    
    QString tablename;
    QString m_sClassname;
    
    QMap<QString, QString> fieldtypemappingqt;
    QMap<QString, QString> fieldtypedefaultvalueqt;
    
    QMap<QString, QString> fieldtypemappingwx;
    QMap<QString, QString> fieldtypedefaultvaluewx;
    
    QString m_sHeaderTemplate;
    QString m_sSourceTemplate;
    
    QString m_sSourceGetters;
    QString m_sSourceSetters;
    
    QString m_sHeaderGetters;
    QString m_sHeaderSetters;
    QString m_sSourceInit;
    QString m_sMember;
    
    QString m_sSource;
    QString m_sHeader;
    
public slots:
    void ConnectToDB();
    void ChooseFile();
    void ReadTables();
    void ReadFields(const QModelIndex & );
    void InitFieldTypeMapping();
    void GenerateHeader();    
    void GenerateSource();
    void GenerateSourceInit();
    
    void GenerateHeaderGetter();    
    void GenerateSourceGetter();
    
    void GenerateHeaderSetter();    
    void GenerateSourceSetter();
    
    void GenerateMembers();
};

#endif // MAINWINDOW_H
