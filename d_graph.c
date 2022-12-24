#include "d_graph.h"


void display_graph_1(double* my_sol, double* x_steps, int n) {

    _Bool success;

    RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
    StringReference *errorMessage = CreateStringReference(L"", 0);
    success = DrawScatterPlot(canvasReference, 600, 400, x_steps, n, my_sol, n, errorMessage);

    if(success){
        size_t length;
        double *pngdata = ConvertToPNG(&length, canvasReference->image);
        WriteToFile(pngdata, length, "graph_12.png");
        DeleteImage(canvasReference->image);
    }else{
        fprintf(stderr, "Error: ");
        for(int i = 0; i < errorMessage->stringLength; i++){
            fprintf(stderr, "%c", errorMessage->string[i]);
        }
        fprintf(stderr, "\n");
    }
}

void display_graph_2(double* my_sol, double* true_sol, double* steps_x, int n){

    _Bool success;
    StringReference* errorMessage;
    RGBABitmapImageReference* imageReference =                        CreateRGBABitmapImageReference();

    ScatterPlotSeries* series = GetDefaultScatterPlotSeriesSettings();
    series->xs = steps_x;
    series->xsLength = n;
    series->ys = my_sol;
    series->ysLength = n;
    series->linearInterpolation = true;
    series->lineType = L"dotted";
    series->lineTypeLength = wcslen(series->lineType);
    series->lineThickness = 2;
    series->color = CreateRGBColor(1, 0, 0);

    ScatterPlotSeries* series2 = GetDefaultScatterPlotSeriesSettings();
    series2->xs = steps_x;
    series2->xsLength = n;
    series2->ys = true_sol;
    series2->ysLength = n;
    series2->linearInterpolation = true;
    series2->lineType = L"dotted";
    series2->lineTypeLength = wcslen(series2->lineType);
    series2->lineThickness = 2;
    series2->color = CreateRGBColor(0, 0, 1);

    ScatterPlotSettings* settings = GetDefaultScatterPlotSettings();
    settings->width = 1920;
    settings->height = 1080;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = L"My title";
    settings->titleLength = wcslen(settings->title);
    settings->xLabel = L"axis X";
    settings->xLabelLength = wcslen(settings->xLabel);
    settings->yLabel = L"axis Y";
    settings->yLabelLength = wcslen(settings->yLabel);
    ScatterPlotSeries* s[] = { series, series2 };
    settings->scatterPlotSeries = s;
    settings->scatterPlotSeriesLength = 2;

    errorMessage = (StringReference*)malloc(sizeof(StringReference));
    success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

    if (success) {
        size_t length;
        double* pngdata = ConvertToPNG(&length, imageReference->image);
        WriteToFile(pngdata, length, "exact_approximates_graph.png");
        DeleteImage(imageReference->image);
    }

}



