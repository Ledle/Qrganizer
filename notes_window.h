#ifndef NOTES_WINDOW_H
#define NOTES_WINDOW_H

#include <QWidget>

namespace Ui {
class notes_window;
}

class notes_window : public QWidget
{
    Q_OBJECT

public:
    explicit notes_window(QWidget *parent = nullptr);
    ~notes_window();

private:
    Ui::notes_window *ui;
};

#endif // NOTES_WINDOW_H
