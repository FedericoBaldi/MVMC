/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011-2018 Emanuel Eichhammer                            **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 25.06.18                                             **
**          Version: 2.0.1                                                **
****************************************************************************/

#pragma once
#include <QWidget>
#include "GUI/qcustomplot.h"
#include "axistag.h"
#include "dataadapter.h"

namespace Ui {
class OriginalPlotAxis;
}

class OriginalPlotAxis : public QCustomPlot
{
  Q_OBJECT
  
public:
  explicit OriginalPlotAxis(DataAdapter *dataAdapter, eDataName dataName, QColor graphColor, QWidget *parent = 0);
  void refresh();
  ~OriginalPlotAxis();
  
private:
  DataAdapter *m_dataAdapter;
  eDataName m_dataName;
  QPointer<QCPGraph> m_Graph;
  QList<AxisTag *> m_TagList;
  QTimer mDataTimer;
  QVector<double> *xValues;
  QVector<double> *yValues;
  int m_currentGraphPos;
  QWidget *m_blackBar;
  static const char * m_titleNameList[];
  static const char * m_measureUnitNameList[];
  static const int GRAPH_VALUES_SIZE;
};
