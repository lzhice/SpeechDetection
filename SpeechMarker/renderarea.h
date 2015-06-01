#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPixmap>
#include <QVector>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(unsigned int initMarkerPos, QWidget *parent = 0);
    ~RenderArea();

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    void setNewSamples(const QVector<int> &newVectSamples, unsigned int maxValue);
    void setMarkerPosition(unsigned int newPosition);
    QVector<int> *samplesVectorPtr(){return vectSamples;}
    QVector<int> *marksVectorPtr(){return vectMarks;}
signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event);
private:
    QPixmap *pixmap;
    QRect *Area;
    QBrush *brBackground;
    QPen *pnAxis, *pnCurve, *pnMarker;
    QPoint *pointLeftAxisEnd, *pointRightAxisEnd, *pointUpperMarkerEnd, *pointLowerMarkerEnd;
    unsigned int markerPos, maxSampleValue;
    QVector<int> *vectSamples, *vectMarks;
    double xScaleSamples, yScaleSamples;
    void drawBackground(QPainter &painter);
    void drawMarker(QPainter &painter);
    void drawAxis(QPainter &painter);
    void drawSamples(QPainter &painter);
    void drawMarks(QPainter &painter);
};

#endif // RENDERAREA_H
