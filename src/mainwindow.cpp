#include "mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), clickCount(0)
{
    // Set window properties
    setWindowTitle("Qt WebAssembly Hello World");
    setMinimumSize(400, 300);
    
    // Create central widget and layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    
    // Create and configure label
    label = new QLabel("Hello World from Qt WebAssembly!", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold; color: #2c3e50; margin: 20px;");
    
    // Create and configure button
    button = new QPushButton("Click Me!", this);
    button->setStyleSheet("font-size: 16px; padding: 10px 20px; background-color: #3498db; color: white; border: none; border-radius: 5px;");
    button->setMaximumWidth(200);
    
    // Add widgets to layout
    layout->addStretch();
    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->addWidget(button, 0, Qt::AlignCenter);
    layout->addStretch();
    
    // Set central widget
    setCentralWidget(centralWidget);
    
    // Connect button signal to slot
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onButtonClicked()
{
    clickCount++;
    label->setText(QString("Button clicked %1 time%2!")
                   .arg(clickCount)
                   .arg(clickCount == 1 ? "" : "s"));
}
