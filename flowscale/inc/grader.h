#ifndef GRADER_H
#define GRADER_H

#include <QThread>




class Grader : public QThread
{
    Q_OBJECT

public:
    explicit Grader(QObject *parent = 0);
    ~Grader();

    void run();





private:







signals:






public slots:





};

#endif // GRADER_H
