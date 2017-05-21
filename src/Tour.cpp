#include "Tour.h"

static bool running = false;

void StartTour() {
	running = true;
	StopMove();
}

void EndTour() {
	running = false;
	StopMove();
}

bool IsTour() {
	return running;
}

void Tour(int i) {
	switch (i) {
	case 0: 
		MoveToPos(glm::vec3(0,34.5,26.6));
		SetForward(glm::vec3(-0.075, -0.9364, -0.3426));
		RotateZ(180);

		break;

	case 10:
		IncreaseSpeed();
		IncreaseSpeed();
		IncreaseSpeed();
		IncreaseSpeed();
		IncreaseSpeed();
		IncreaseSpeed();
		IncreaseSpeed();
		IncreaseSpeed();
		IncreaseSpeed();
		break;

	case 200:
		RotateX(-1);
		break;

	case 201:
		RotateX(-1);
		break;

	case 202:
		RotateX(-1);
		break;

	case 203:
		RotateX(-1);
		break;

	case 204:
		RotateX(-1);
		break;

	case 205:
		RotateX(-1);
		break;

	case 206:
		RotateX(-1);
		break;

	case 207:
		RotateX(-1);
		break;

	case 208:
		RotateX(-2);
		break;

	case 209:
		RotateX(-2);
		break;

	case 210:
		RotateX(-2);
		break;

	case 211:
		RotateX(-2);
		break;

	case 212:
		RotateX(-2);
		break;

	case 213:
		RotateX(-2);
		break;

	case 214:
		RotateX(-2);
		break;

	case 215:
		RotateX(-2);
		break;

	case 216:
		RotateX(-2);
		break;

	case 217:
		RotateX(-1);
		break;

	case 218:
		RotateX(-1);
		break;

	case 219:
		RotateX(-1);
		break;

	case 500:
		RotateY(3);
		break;

	case 501:
		RotateY(3);
		break;

	case 502:
		RotateY(3);
		break;

	case 503:
		RotateY(3);
		break;

	case 504:
		RotateY(3);
		break;

	case 505:
		RotateY(3);
		break;

	case 506:
		RotateY(3);
		RotateZ(5);
		break;

	case 507:
		RotateY(3);
		RotateZ(5);
		break;

	case 508:
		RotateY(3);
		RotateZ(5);
		break;

	case 509:
		RotateY(3);
		RotateZ(5);
		break;

	case 510:
		RotateY(3);
		RotateZ(5);
		break;

	case 511:
		RotateY(3);
		RotateZ(5);
		break;

	case 512:
		RotateY(3);
		RotateZ(5);
		break;

	case 513:
		RotateY(3);
		RotateZ(5);
		break;

	case 514:
		RotateY(3);
		RotateZ(5);
		break;

	case 700:
		RotateX(5);
		RotateY(5);
		break;

	case 701:
		RotateX(5);
		RotateY(5);
		break;

	case 702:
		RotateX(5);
		RotateY(5);
		break;

	case 703:
		RotateX(5);
		RotateY(5);
		RotateZ(5);
		break;

	case 1000:
		RotateX(5);
		RotateY(-10);
		break;

	case 1001:
		RotateY(-10);
		break;

	case 1002:
		RotateX(5);
		RotateY(-10);
		break;

	case 1200:
		RotateX(5);
		RotateY(-10);
		break;

	case 1201:
		RotateY(-10);
		break;

	case 1202:
		RotateY(-10);
		break;

	case 1203:
		RotateY(-10);
		break;

	case 1204:
		RotateY(-10);
		break;

	case 1206:
		RotateY(-10);
		RotateZ(-5);
		DecreaseSpeed();
		DecreaseSpeed();
		DecreaseSpeed();
		break;

	case 1370:
		RotateY(-15);
		break;

	case 1371:
		RotateY(-15);
		break;

	case 1372:
		RotateY(-15);
		break;

	case 1373:
		RotateY(-15);
		break;

	case 1374:
		RotateY(-15);
		break;

	case 2000:
		DecreaseSpeed();
		DecreaseSpeed();
		DecreaseSpeed();
		DecreaseSpeed();
		DecreaseSpeed();
		DecreaseSpeed();

		RotateY(5);
		break;

	case 2001:
		RotateY(5);
		break;

	case 2002:
		RotateY(5);
		break;

	case 2003:
		RotateY(5);
		break;

	case 2004:
		RotateY(5);
		break;

	case 2005:
		RotateY(5);
		break;

	case 2006:
		RotateY(5);
		break;

	case 2007:
		RotateY(5);
		break;

	case 2008:
		RotateY(5);
		break;

	case 2009:
		RotateY(5);
		break;

	case 2010:
		RotateY(5);
		break;

	case 2011:
		RotateY(5);
		break;

	case 2012:
		RotateY(5);
		break;

	case 2013:
		RotateY(5);
		break;

	case 2014:
		RotateY(5);
		break;

	case 2015:
		RotateY(5);
		break;

	case 2016:
		RotateY(5);
		break;

	case 2017:
		RotateY(5);
		break;

	case 2018:
		RotateY(5);
		break;

	case 2019:
		RotateY(5);
		break;

	case 2020:
		RotateY(5);
		break;

	case 3100:
		RotateX(5);
		break;

	case 3101:
		RotateX(5);
		break;

	case 3102:
		RotateX(5);
		break;

	case 3103:
		RotateX(5);
		break;

	case 3104:
		RotateX(5);
		break;

	case 3105:
		RotateX(5);
		break;

	case 3106:
		RotateX(5);
		break;

	case 3107:
		RotateX(5);
		break;

	case 3108:
		RotateX(5);
		break;

	case 3109:
		RotateX(5);
		break;

	case 3110:
		RotateX(5);
		break;

	case 3111:
		RotateX(5);
		break;

	case 3200:
		EndTour();
		break;
		
	default:
		break;
	}
}