node {
	stage('Checkout') {
		checkout scm
	}
	stage('Build') {
		echo 'Build Stage';
		try {
			sh 'qmake string-test.pro'
			sh 'make'
		} catch(Exception e) {
			sh 'g++ test.cpp -std=c++11'
		}
	}
	stage('Send') {
		echo 'Send Stage';
	}
}
