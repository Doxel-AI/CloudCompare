/*#include "RegistrationTools.h"

//local
#include "GenericProgressCallback.h"
#include "ReferenceCloud.h"
#include "DistanceComputationTools.h"
#include "CloudSamplingTools.h"
#include "ScalarFieldTools.h"
#include "NormalDistribution.h"
#include "ManualSegmentationTools.h"
#include "GeometricalAnalysisTools.h"
#include "KdTree.h"
#include "SimpleCloud.h"
#include "ChunkedPointCloud.h"
#include "Garbage.h"
#include "Jacobi.h"
#include "SortAlgo.h"

//system
#include <time.h>

using namespace CCLib;
*/

#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
//#include <pcl/visualization/pcl_visualizer.h>

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>



#include "ccRegistrationTools.h"
#include "ccHObject.h"
//#include "qPCL/PclIO/PcdFilter.h"
//#include "qPCL/PclIO/qPclIO.h"
//#include "qPCL/PclUtils/utils/sm2cc.h"


#include <ccPointCloud.h>

//#include "libs/qCC_io/FileIOFilter.h"

//CCLib
#include <MeshSamplingTools.h>
#include <GenericIndexedCloudPersist.h>
#include <SimpleCloud.h>
#include <RegistrationTools.h>
#include <DistanceComputationTools.h>
#include <CloudSamplingTools.h>
#include <Garbage.h>
#include <SortAlgo.h>

//qCC_db
#include <ccHObjectCaster.h>
#include <ccPointCloud.h>
#include <ccGenericMesh.h>
#include <ccProgressDialog.h>
#include <ccScalarField.h>
#include <ccLog.h>

//system
#include <set>

#include <string>

#define FROM_PCL_CLOUD pcl::fromPCLPointCloud2


std::string model_path("model.pcd");
std::string crop_path("crop.pcd");

//ccPointCloud* 
void pcl2cc(pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud, ccPointCloud* cc_cloud);

//ccPointCloud* 
void pcl2cc(pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloud, ccPointCloud* cc_cloud) {

/*
	//loop
	for (size_t i = 0; i < pointCount; ++i)
	{
		CCVector3 P(pcl_cloud->at(i).x,
					pcl_cloud->at(i).y,
					pcl_cloud->at(i).z);

		cloud->addPoint(P);
	}
*/
}



int main() {

	//
	// Read model pcd
	//
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_model(new pcl::PointCloud<pcl::PointXYZ>());
	//
  if (pcl::io::loadPCDFile<pcl::PointXYZ> (model_path, *pcl_model) == -1) //* load the file 
  {	
    PCL_ERROR ("Couldn't read model file \n"); 
    return (-1); 
  } 
  std::cout << "Loaded " 
            << pcl_model->width * pcl_model->height 
            << " data points from model pcd" 
            << std::endl; 
	//
	// Read crop pcd
	//
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_crop(new pcl::PointCloud<pcl::PointXYZ>());
  //
  if (pcl::io::loadPCDFile<pcl::PointXYZ> (crop_path, *pcl_crop) == -1) //* load the file 
  {	
    PCL_ERROR ("Couldn't read crop file \n"); 
    return (-1); 
  } 
  std::cout << "Loaded " 
            << pcl_crop->width * pcl_crop->height 
            << " data points from crop pcd" 
            << std::endl; 
  //
	// Convert model pcd to CloudCompare cloud
	//
  ccPointCloud* cc_model = new ccPointCloud();
  pcl2cc(pcl_model, cc_model);
  //
	// Convert crop pcd to CloudCompare cloud
	//
  ccPointCloud* cc_crop = new ccPointCloud();
  pcl2cc(pcl_crop, cc_crop);





  //CCLib::FPCSRegistrationTools::ScaledTransformation inTrans;

  //PcdFilter *pcdReader = new PcdFilter;


  //ccPointCloud* cropCloud = new ccPointCloud();


	//pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud (new pcl::PointCloud<pcl::PointXYZ>);
  //pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud (new pcl::PointCloud<pcl::PointXYZ> ());

  //ccPointCloud* ccCloud = sm2ccConverter(pcl_cloud).getCloud();


  //push points inside
	// if (!addXYZ(cloud))
	// {
	// 	delete cloud;
	// 	return 0;
	// }


  ccHObject *crop = NULL;
  ccHObject *model = NULL;
	ccGLMatrix transMat;

  double finalScale = 0;
	double finalRMS = 0;
	unsigned finalPointCount = 0;
	double minRMSDecrease = 0;
	unsigned maxIterationCount = 0;
	unsigned randomSamplingLimit = 0;
	bool removeFarthestPoints = 0;
	CCLib::ICPRegistrationTools::CONVERGENCE_TYPE method = CCLib::ICPRegistrationTools::CONVERGENCE_TYPE::MAX_ERROR_CONVERGENCE;
  bool adjustScale = false;

  printf("Hello!\n");


  

/*
  ccRegistrationTools::ICP(
    crop,
    model,
    transMat,
    finalScale,
		finalRMS,
		finalPointCount,
	  minRMSDecrease,
		maxIterationCount,
		randomSamplingLimit,
		removeFarthestPoints,
		method,
	  adjustScale
  );
*/
  printf("Hello again!\n");

  return 0;
}
