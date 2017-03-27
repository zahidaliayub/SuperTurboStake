#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

namespace Ui {
    class OverviewPage;
}
class WalletModel;
class TxViewDelegate;

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

    void setModel(WalletModel *model);

public slots:
    void setBalance(qint64_t balance, qint64_t stake, qint64_t unconfirmedBalance);
    void setNumTransactions(int count);

signals:
    void transactionClicked(const QModelIndex &index);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::OverviewPage *ui;
    WalletModel *model;
    qint64_t currentBalance;
    qint64_t currentStake;
    qint64_t currentUnconfirmedBalance;

    TxViewDelegate *txdelegate;
    unsigned int numDisplayedTransactions();

private slots:
    void displayUnitChanged();
};

#endif // OVERVIEWPAGE_H
