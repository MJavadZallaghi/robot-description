#include <iostream>

#include <sdf/sdf.hh>

int main(int argc, const char* argv[])
{

  // Understand argc and argv: 
  // argc: int of separated line strings by space
  // argv: array of separated string inputs

  // example:
  // ./check_sdf ../sdf_models/model-1_4.sdf
  // argc = 2, argv[0] = ./check_sdf, argv[1] = ../sdf_models/model-1_4.sdf
  std::cout << "argc: " << argc << "\nargv[0]: " << argv[0] 
                                << "\nargv[1]: " << argv[1] <<std::endl;

  // check arguments
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0]
              << " <sdf-path>" << std::endl;
    return -1;
  }
  const std::string sdfPath(argv[1]);
  std::cout << "sdfPath: " << sdfPath <<std::endl;

  // load and check sdf file
  sdf::SDFPtr sdfElement(new sdf::SDF());
  sdf::init(sdfElement);
  if (!sdf::readFile(sdfPath, sdfElement))
  {
    std::cerr << sdfPath << " is not a valid SDF file!" << std::endl;
    return -2;
  }

  // start parsing model
  const sdf::ElementPtr rootElement = sdfElement->Root();
  if (!rootElement->HasElement("model"))
  {
    std::cerr << sdfPath << " is not a model SDF file!" << std::endl;
    return -3;
  }
  const sdf::ElementPtr modelElement = rootElement->GetElement("model");
  const std::string modelName = modelElement->Get<std::string>("name");
  std::cout << "Found " << modelName << " model!" << std::endl;

  // parse model links
  sdf::ElementPtr linkElement = modelElement->GetElement("link");
  while (linkElement)
  {
    const std::string linkName = linkElement->Get<std::string>("name");
    std::cout << "Found " << linkName << " link in "
              << modelName << " model!" << std::endl;
    linkElement = linkElement->GetNextElement("link");
  }

  // parse model joints
  sdf::ElementPtr jointElement = modelElement->GetElement("joint");
  while (jointElement)
  {
    const std::string jointName = jointElement->Get<std::string>("name");
    std::cout << "Found " << jointName << " joint in "
              << modelName << " model!" << std::endl;

    const sdf::ElementPtr parentElement = jointElement->GetElement("parent");
    const std::string parentLinkName = parentElement->Get<std::string>();

    const sdf::ElementPtr childElement = jointElement->GetElement("child");
    const std::string childLinkName = childElement->Get<std::string>();

    std::cout << "Joint " << jointName << " connects " << parentLinkName
              << " link to " << childLinkName << " link" << std::endl;

    jointElement = jointElement->GetNextElement("joint");
  }

  return 0;
}