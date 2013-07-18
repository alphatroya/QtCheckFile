#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <QObject>
#include <QtCore>

class FileFinder : public QObject
{
    Q_OBJECT
public:
    explicit FileFinder(QObject *parent = 0);
    void findFiles(QDir&);
    void setMaskFiles(QString);
    void setFileDirectory(QString);
    void setSearchWord(QString);

signals:
    void result(QString);

public slots:

private:
    void findAndShow(QString, QString);
    QString maskFiles, fileDirrectory, searchWord;



};

#endif // FILEFINDER_H
