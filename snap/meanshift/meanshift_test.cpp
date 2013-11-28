#include "snap/meanshift/meanshift.h"
#include "snap/google/base/integral_types.h"
#include "snap/opencv2/core/core.hpp"
#include <iostream>

using namespace std;
using namespace meanshift;

int main(int argc, char *argv[]) {

  /*
  float test_data[] = {6.107759,6.140662,7.066949,6.868925,
          1.068378,1.273457,1.951643,2.112667,
          0.919757,1.255738,1.750059,1.938757,
  };
  */

  float test_data[] = {6.107759,6.140662,7.066949,6.868925,
        1.068378,1.273457,1.951643,2.112667,
        0.919757,1.255738,1.750059,1.938757,
        2.678445,3.083686,3.728631,3.795239,
        3.002063,3.133848,3.815505,3.414493,
        6.113307,5.979111,6.926524,6.980171,
        0.903171,1.118306,5.795484,5.795707,
        5.655913,6.188857,7.106792,7.286044,
        1.277350,0.952816,5.936408,5.795246,
        2.980771,3.396625,3.735364,3.742637,
        0.898148,0.929664,1.949629,1.838306,
        0.907886,1.098685,1.924138,1.485643,
        0.799199,1.159486,6.411870,5.588575,
        2.964762,3.330009,3.811249,4.023316,
        3.050474,3.374649,3.911137,4.217539,
        3.075745,2.993085,4.050874,3.964700,
        6.080222,5.736667,7.256663,6.963456,
        2.632353,2.754971,3.783156,3.658666,
        6.074378,6.235710,6.924823,7.101806,
        1.131860,1.504478,6.366347,6.256095,
        1.171052,1.185212,6.051590,5.643465,
        5.559049,6.078489,6.758677,6.598881,
        5.718466,5.683817,7.625567,7.056784,
        0.945090,1.263609,2.099048,2.391828,
        1.058180,1.139878,2.099169,1.783265,
        1.106328,1.345052,2.116339,2.273369,
        2.910213,2.871219,3.982461,4.402553,
        0.891239,0.989344,5.833302,6.260549,
        1.014283,1.197826,5.836630,6.322067,
        0.787754,1.305183,1.201672,2.196821,
    };


  cv::Mat test_data_mat(30, 4, CV_32F, test_data);

  cv::Mat centers;
  std::vector<uint32> labels;


  double bandwidth = 0;

  if (!EstimateBandwidth(test_data_mat, 0.2, 500, &bandwidth)){
    bandwidth = 10;
  }

  cout << "bandwidth: " << bandwidth << endl;

  GenerateClusterLabels(test_data_mat, bandwidth, &centers, &labels);

  cout << "num clusters: " << centers.rows << endl;

  for (uint32 i=0; i < labels.size(); ++i){
    cout << labels[i] << endl;
  }

}

