#include <glew.h>
#include <utils.h>
#include <QGLViewer/qglviewer.h>
#include <glcheck.h>

using namespace std;


GLuint loadTexture(const char* filename)
{
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    QImage img = QGLWidget::convertToGLFormat(QImage(filename));
    GLCHECK(glBindTexture(GL_TEXTURE_2D, id));
    GLCHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width(), img.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img.bits()));
    GLCHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    glDisable(GL_TEXTURE_2D);
    return id;
}

void Vecteur_Unite(float vector[3])
{
       float length;

            // Calcul de la norme du vecteur
       length = (float)sqrt((vector[0]*vector[0]) + (vector[1]*vector[1]) + (vector[2]*vector[2]));

       if(length == 0.0f) length = 1.0f;  //évite une violente erreur !!!
       vector[0] /= length;
       vector[1] /= length;
       vector[2] /= length;
}

// Points p1, p2, & p3 spécifiés dans le sens trigonométrique
void Normale(float v[3][3], float out[3])
{
       float v1[3],v2[3];
       static const int x = 0;
       static const int y = 1;
       static const int z = 2;

            // Calcul de 2 vecteurs à partir des 3 points
       v1[x] = v[0][x] - v[1][x];
       v1[y] = v[0][y] - v[1][y];
       v1[z] = v[0][z] - v[1][z];
       v2[x] = v[1][x] - v[2][x];
       v2[y] = v[1][y] - v[2][y];
       v2[z] = v[1][z] - v[2][z];

            // calcul du produit vectoriel
       out[x] = (v1[y]*v2[z] - v1[z]*v2[y]);
       out[y] = (v1[z]*v2[x] - v1[x]*v2[z]);
       out[z] = (v1[x]*v2[y] - v1[y]*v2[x]);

        // on le réduit à un vecteur unité
       Vecteur_Unite(out);
}

void MakeShadowMatrix(GLfloat points_plan[3][3], GLfloat lightPos[4], GLfloat destMat[4][4])
{
    GLfloat planeCoeff[4];
    GLfloat dot;


        //on calcule un vecteur normal à ce plan
    Normale(points_plan,planeCoeff);


        // le dernier coefficient se calcule par substitution
    planeCoeff[3] = - ( (planeCoeff[0]*points_plan[2][0]) + (planeCoeff[1]*points_plan[2][1]) + (planeCoeff[2]*points_plan[2][2]));
    dot = planeCoeff[0] * lightPos[0] + planeCoeff[1] * lightPos[1] + planeCoeff[2] * lightPos[2] + planeCoeff[3] * lightPos[3];


        // maintenant, on projète
        // 1ère colonne
    destMat[0][0] = dot - lightPos[0] * planeCoeff[0];
    destMat[1][0] = 0.0f - lightPos[0] * planeCoeff[1];
    destMat[2][0] = 0.0f - lightPos[0] * planeCoeff[2];
    destMat[3][0] = 0.0f - lightPos[0] * planeCoeff[3];


        // 2ème colonne
    destMat[0][1] = 0.0f - lightPos[1] * planeCoeff[0];
    destMat[1][1] = dot - lightPos[1] * planeCoeff[1];
    destMat[2][1] = 0.0f - lightPos[1] * planeCoeff[2];
    destMat[3][1] = 0.0f - lightPos[1] * planeCoeff[3];


        // 3ème colonne
    destMat[0][2] = 0.0f - lightPos[2] * planeCoeff[0];
    destMat[1][2] = 0.0f - lightPos[2] * planeCoeff[1];
    destMat[2][2] = dot - lightPos[2] * planeCoeff[2];
    destMat[3][2] = 0.0f - lightPos[2] * planeCoeff[3];


        // 4ème colonne
    destMat[0][3] = 0.0f - lightPos[3] * planeCoeff[0];
    destMat[1][3] = 0.0f - lightPos[3] * planeCoeff[1];
    destMat[2][3] = 0.0f - lightPos[3] * planeCoeff[2];
    destMat[3][3] = dot - lightPos[3] * planeCoeff[3];
}
