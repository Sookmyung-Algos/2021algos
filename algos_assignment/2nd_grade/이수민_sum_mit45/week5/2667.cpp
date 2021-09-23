		for (int j = 0; j < n; j++)
			scanf("%1d", &graph[i][j]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			if (dfs(i, j)) {
				count += 1;
				group.push_back(cnt);
			}
		}
	}

	sort(group.begin(), group.end());

	cout << count << endl; // 단지 개수
	for (int i = 0; i < group.size(); i++) {
		cout << group[i] << endl; // 집 개수 출력
	}
}
