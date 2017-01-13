node {
	stage('Build') {
		echo 'Build Stage';
		qmakebuilder string-test.pro;
		make;
	}
	stage('Send') {
		echo 'Send Stage';
	}
}
