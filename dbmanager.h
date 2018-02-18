#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class DbManager
{
public:
    struct DataBlock{
        QString validez;
        int latitud;
        int longitud;
        int velocidad;
        QString pulsacion;
    };

    DbManager(const QString& path);
    ~DbManager();
    bool isOpen() const;
    bool createTable(QString);
    bool removeTable(QString);
    bool addData(QString, DataBlock);
    QStringList obtenerLista();

    bool personExists(const QString& name) const;
    void printAllPersons() const;
    bool removeAllPersons();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
