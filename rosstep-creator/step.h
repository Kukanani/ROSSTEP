///////////////////////////////////////////////////////////////////////////////
//      Title     : Step
//      Project   : ROSSTEP
//      Created   : 7/31/2015
//      Author    : Adam Allevato
//      Platforms : Ubuntu 64-bit
//      Copyright : Copyright© The University of Texas at Austin, 2014-2017. All rights reserved.
//                 
//          All files within this directory are subject to the following, unless an alternative
//          license is explicitly included within the text of each file.
//
//          This software and documentation constitute an unpublished work
//          and contain valuable trade secrets and proprietary information
//          belonging to the University. None of the foregoing material may be
//          copied or duplicated or disclosed without the express, written
//          permission of the University. THE UNIVERSITY EXPRESSLY DISCLAIMS ANY
//          AND ALL WARRANTIES CONCERNING THIS SOFTWARE AND DOCUMENTATION,
//          INCLUDING ANY WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//          PARTICULAR PURPOSE, AND WARRANTIES OF PERFORMANCE, AND ANY WARRANTY
//          THAT MIGHT OTHERWISE ARISE FROM COURSE OF DEALING OR USAGE OF TRADE.
//          NO WARRANTY IS EITHER EXPRESS OR IMPLIED WITH RESPECT TO THE USE OF
//          THE SOFTWARE OR DOCUMENTATION. Under no circumstances shall the
//          University be liable for incidental, special, indirect, direct or
//          consequential damages or loss of profits, interruption of business,
//          or related expenses which may arise from use of software or documentation,
//          including but not limited to those resulting from defects in software
//          and/or documentation, or loss or inaccuracy of data of any kind.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef STEP_H
#define STEP_H

#include <QWidget>
#include <QVBoxLayout>

//predefines
namespace Ui {
class Step;
}

/**
 * @brief A one-to-one mapping to a single step of a rosstep routine.
 */
class Step : public QWidget
{
    Q_OBJECT

public:
    explicit Step(QWidget *parent = 0);
    ~Step();

    /**
     * @brief Get the type of action for this step
     * @return The text of the action combo box
     */
    std::string getAction();
    /**
     * @brief Get the action meta-text for this step
     * @return The text of the action edit box
     */
    std::string getActionText();

    /**
     * @brief Get the condition to watch before moving on from this step
     * @return The text of the condition combo box
     */
    std::string getCondition();
    /**
     * @brief Get the condition meta-text for this step's condition
     * @return The text of the condition edit box
     */
    std::string getConditionText();

    /**
     * @brief Generate a full representation of this step in YAML format
     * @return A YAML string with the relevant elements for this step
     */
    std::string produceYAML();

    /**
     * @brief Move this interface element upwards in the stack (towards the beginning of the program).
     */
    void moveUp();
    /**
     * @brief Move this interface element downwards in the stack (towards the end of the program).
     */
    void moveDown();
    /**
     * @brief Update all the up/down buttons of all sibling Steps based on their stack position.
     */
    void refreshUpDownButtons(QVBoxLayout* layout);
    /**
     * @brief Enable or disable the up/down buttons based on stack position
     */
    void checkUpDownButtons(QVBoxLayout* layout);

    /**
     * @brief Ensure that all inputs in this Step's interface make sense.
     *
     * Checks that numbers are supplied for number fields, and that required fields are not empty. Incorrectly-filled fields highlight pink.
     *
     * @return true if all the inputs are valid, false if otherwise
     */
    bool validate();

private slots:
    void on_pushButton_clicked();
    void on_action_combo_currentTextChanged(const QString &arg1);
    void on_condition_combo_currentTextChanged(const QString &arg1);
    void on_upButton_clicked();
    void on_downButton_clicked();

private:
    Ui::Step *ui;
};

#endif // STEP_H
