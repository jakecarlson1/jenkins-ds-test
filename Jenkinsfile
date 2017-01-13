node {
	stage('Build') {
		echo 'Build Stage';
		sh 'qmake string-test.pro'
		sh 'make'
	}
	stage('Send') {
		echo 'Send Stage';
	}
}
