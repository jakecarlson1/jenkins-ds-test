node {
	stage('Checkout') {
		checkout scm
	}
	stage('Build') {
		echo 'Build Stage';
		try {
			sh 'qmake ll-test.pro'
			sh 'make'
		} catch(Exception e) {
			sh 'g++ tests.cpp -std=c++11'
		}
	}
	stage('Run') {
		testResults = sh(returnStdout: true, script: './a.out').trim()
		echo testResults
	}
	stage('Send') {
		echo 'Send Stage'
	}
}
