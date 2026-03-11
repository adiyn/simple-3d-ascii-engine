#include "math_utils.h"
#include <stdlib.h>

Vector2D setVector2D(double x, double y) {
    Vector2D v2D = {x, y};
    return v2D;
}

Vector3D setVector3D(double x, double y, double z) {
    Vector3D v3D = {x, y, z};
    return v3D;
}

Point3D setPoint3D(double x, double y, double z) {
    Point3D p3D = {{x, y, z}, 0.0};
    return p3D;
}

Point2D setPoint2D(double x, double y) {
    Point2D p2D = {{x, y}, 0.0};
    return p2D;
}

double getRadius(double x, double y, double x1, double y1) {
    double dx = x - x1;
    double dy = y - y1;
    return sqrt(dx*dx + dy*dy);
}

double distanceFromCamera(Point3D point, Camera camera) {
    return sqrt(pow(point.vectPnt.x - camera.vectCam.x, 2) + 
                pow(point.vectPnt.y - camera.vectCam.y, 2) + 
                pow(point.vectPnt.z - camera.vectCam.z, 2));
}

Point2D getPoint2DFromPoint3D(Point3D p3D, Camera camera) {
    double relativeX = p3D.vectPnt.x - camera.vectCam.x;
    double relativeY = p3D.vectPnt.y - camera.vectCam.y;
    double relativeZ = p3D.vectPnt.z - camera.vectCam.z;

    if (relativeZ > 0.1) {
        double projectedX = (relativeX * FOCAL_LENGTH / relativeZ) * 2.0;
        double projectedY = relativeY * FOCAL_LENGTH / relativeZ;
        
        Point2D p2D = {{projectedX, projectedY}, p3D.light_intensity};
        return p2D;
    }
    Point2D p2D = {EMPTY_POINT2D};
    return p2D;
}

Vector2D getVector2DFromVector3D(Vector3D vect3D, Camera camera) {
    double relativeX = vect3D.x - camera.vectCam.x;
    double relativeY = vect3D.y - camera.vectCam.y;
    double relativeZ = vect3D.z - camera.vectCam.z;

    if (relativeZ > 0.1) {
        double projectedX = (relativeX * FOCAL_LENGTH / relativeZ) * 2.0;
        double projectedY = relativeY * FOCAL_LENGTH / relativeZ;

        Vector2D vect2D = {projectedX, projectedY};
        return vect2D;
    }
    Vector2D vect2D = {EMPTY_VECT2D};
    return vect2D;
}

void setLightIntensity(Point3D* point, LightSource light) {
    double distance = distanceFromCamera(*point, (Camera){light.vectLgt});
    if (distance < 0.1) distance = 0.1;
    point->light_intensity = 1.0 / (distance * distance); 
}
