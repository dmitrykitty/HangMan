#pragma once

#include <ui_mainwindow.h>
#include "GameController/GameController.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    Ui::MainWindow* ui;
    GameController controller_;

    enum PageIndex {
        PageMenu = 0,
        PageGame = 1,
        PageAbout = 2,
        PageSettings = 3
    };

    static inline const QString aboutText =
    "<b>HangMan Qt — wersja 1.0</b><br/>"
    "Autor: Dmitry_kitty<br/>"
    "Repozytorium: <a href=\"https://github.com/Dmitry_kitty/MyString\">HangMan</a><br/>"
    "Zapraszam do lajkowania:)<br/><br/>"
    "Klasyczna gra w wisielca, wzbogacona o:<br/>"
    "• Trzy poziomy trudności (Łatwy, Średni, Trudny)<br/>"
    "• Edukacyjny słownik pojęć C++<br/>"
    "• Możliwość dodawania własnych słów i definicji<br/>"
    "• Intuicyjny interfejs Qt z obrazkami wisielca<br/>"
    "• Ustawienia: czyszczenie listy słów, zmiana poziomu trudności<br/><br/>"
    "© 2025 Dmitry_kitty";

    const std::array<QString, 8> hangmanImages = {
        QStringLiteral(":/img/GUI/Resources/img/GameImg0.png"),
        QStringLiteral(":/img/GUI/Resources/img/GameImg1.png"),
        QStringLiteral(":/img/GUI/Resources/img/GameImg2.png"),
        QStringLiteral(":/img/GUI/Resources/img/GameImg3.png"),
        QStringLiteral(":/img/GUI/Resources/img/GameImg4.png"),
        QStringLiteral(":/img/GUI/Resources/img/GameImg5.png"),
        QStringLiteral(":/img/GUI/Resources/img/GameLoseImg.png"),
        QStringLiteral(":/img/GUI/Resources/img/GameWonImg.png")
    };

    const int sz = hangmanImages.size();

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

signals:
    void changeDifficultyRequested();

    void addWordRequested();

private slots:
    //metody nacisku na buttons(wymagające connect)

    void startGameClicked();

    void difficultyClicked();

    void addWordClicked();

    void settingsClicked() const;

    void aboutClicked() const;

    void exitClicked();

    void backClicked() const;

    void pauseClicked();

    void newGameClicked();

    void showDefinitionClicked() const;

    void onLetterClicked(QChar ch);

    void updateGameImage(int errorCount) const;

    void updateGameLabel(const QString& newDisplay) const;

    void updateDescriptionLabel(const QString& newDescription) const;

    void beginNewGame();

    void onGameLost(const QString& secretWord) const;

    void updateAttemptsLabel(int remaining) const;

    void updateDifficultyLabel() const;

    void onUserWordsRemoved(bool success);

private:
    //game GUI update

    void showWonImage() const;

    void showLoseImage() const;

    void finishRound(bool won) const;
};
